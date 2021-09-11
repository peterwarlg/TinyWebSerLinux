//
// Created by marvinle on 2019/2/1 7:34 PM.
//

#include "../../include/Server.h"
#include "../../include/HttpParse.h"
#include "../../include/HttpResponse.h"
#include "../../include/ThreadPool.h"
#include "../../include/HttpData.h"
#include "../../include/Epoll.h"
#include "../../include/Util.h"

#include <unistd.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <string>
#include <functional>
#include <sys/epoll.h>
#include <vector>
#include <cstring>
#include "../../include/HttpData.h"

extern MemoryPool* mempool;

void deleter(HttpData *p) {
//    printf("%s\n", "++++++++++ deleter ++++++++++");
    p->~HttpData();
    mempool->Deallocate(p);
}


char NOT_FOUND_PAGE[] = "<html>\n"
                        "<head><title>404 Not Found</title></head>\n"
                        "<body bgcolor=\"white\">\n"
                        "<center><h1>404 Not Found</h1></center>\n"
                        "<hr><center>LC WebServer/0.3 (Linux)</center>\n"
                        "</body>\n"
                        "</html>";

char FORBIDDEN_PAGE[] = "<html>\n"
                        "<head><title>403 Forbidden</title></head>\n"
                        "<body bgcolor=\"white\">\n"
                        "<center><h1>403 Forbidden</h1></center>\n"
                        "<hr><center>LC WebServer/0.3 (Linux)</center>\n"
                        "</body>\n"
                        "</html>";

char INDEX_PAGE[] = "<!DOCTYPE html>\n"
                    "<html>\n"
                    "<head>\n"
                    "    <title>Welcome to LC WebServer!</title>\n"
                    "    <style>\n"
                    "        body {\n"
                    "            width: 35em;\n"
                    "            margin: 0 auto;\n"
                    "            font-family: Tahoma, Verdana, Arial, sans-serif;\n"
                    "        }\n"
                    "    </style>\n"
                    "</head>\n"
                    "<body>\n"
                    "<h1>Welcome to LC WebServer!</h1>\n"
                    "<p>If you see this page, the lc webserver is successfully installed and\n"
                    "    working. </p>\n"
                    "\n"
                    "<p>For online documentation and support please refer to\n"
//                    "    <a href=\"https://github.com/MarvinLe/WebServer\">LC WebServer</a>.<br/>\n"
                    "    <a href=\"pages/bookmark.html\">LC WebServer</a>.<br/>\n"
                    "\n"
                    "<p><em>Thank you for using LC WebServer.</em></p>\n"
                    "</body>\n"
                    "</html>";

char TEST[] = "HELLO WORLD";

extern std::string basePath;


void HttpServer::run(int thread_num, int max_queque_size) {
    ThreadPool threadPool(thread_num, max_queque_size);
    int epoll_fd = Epoll::init(1024);

    //内存池方法，另一处在Epoll.cpp
    std::shared_ptr<HttpData> httpData(new(mempool) HttpData(), deleter);

//    std::shared_ptr<HttpData> httpDataa(new(mempool) HttpData(), deleter);
//    std::shared_ptr<HttpData> httpData = httpDataa;

    //原版new方法
//    std::shared_ptr<HttpData> httpData(::new HttpData());

    httpData->epoll_fd = epoll_fd;
    serverSocket.epoll_fd = epoll_fd;   // 之前就是这里忘了添加,导致穿进去的serverSocket具有不正确的epoll_fd

    __uint32_t event = (EPOLLIN | EPOLLET);
    Epoll::addfd(epoll_fd, serverSocket.listen_fd, event, httpData);

    while (true) {
        std::vector<std::shared_ptr<HttpData>> events = Epoll::poll(serverSocket, 1024, -1);
        // FIXME 将事件传递给 线程池
        for (auto& req : events) {
            threadPool.append(req, std::bind(&HttpServer::do_request, this, std::placeholders::_1));
        }
        // 处理定时器超时事件
        Epoll::timerManager.handle_expired_event();
    }
}


void HttpServer::do_request(std::shared_ptr<void> arg) {
    std::shared_ptr<HttpData> sharedHttpData = std::static_pointer_cast<HttpData>(arg);

    char buffer[BUFFERSIZE];

    bzero(buffer, BUFFERSIZE);
    int check_index = 0, read_index = 0, start_line = 0;
    ssize_t recv_data;
    HttpRequestParser::PARSE_STATE  parse_state = HttpRequestParser::PARSE_REQUESTLINE;

    while (true) {

        // FIXME 这里也是同样的，由于是非阻塞IO，所以返回-1 也不一定是错误，还需判断error
        recv_data = recv(sharedHttpData->clientSocket_->fd, buffer + read_index, BUFFERSIZE - read_index, 0);
        if (recv_data == -1) {
            if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                return;  // FIXME 请求不完整该怎么办，继续加定时器吗？还是直接关闭
            }
            std::cout << "reading faild" << std::endl;
            return;
        }
        // todo 返回值为 0对端关闭, 这边也应该关闭定时器
//        std::cout << "recv_data: " << recv_data << std::endl;
        if (recv_data == 0) {
//            std::cout << "connection closed by peer" << std::endl;
            break;
        }

        read_index += recv_data;

        HttpRequestParser::HTTP_CODE  retcode = HttpRequestParser::fooParseContent(
                buffer, check_index, read_index, parse_state, start_line, *sharedHttpData->request_);

        if (retcode == HttpRequestParser::NO_REQUEST) {
            continue;
        }


        if (retcode == HttpRequestParser::GET_REQUEST) {
            // FIXME 检查 keep_alive选项
            auto it = sharedHttpData->request_->mHeaders.find(HttpRequest::Connection);
            if (it != sharedHttpData->request_->mHeaders.end()) {
                if (it->second == "keep-alive") {
                    sharedHttpData->response_->setKeepAlive(true);
                    // timeout=20s
                    sharedHttpData->response_->addHeader("Keep-Alive", std::string("timeout=20"));
                } else {
                    sharedHttpData->response_->setKeepAlive(false);
                }
            }
            //设置response的版本 reponse_->mVersion ： HTTP1.0 or HTTP 1.1
            fooHeader(sharedHttpData);
            fooGetMime(sharedHttpData);
            // FIXME 之前测试时写死的了文件路径导致上服务器出错
            //fooStaticFile(sharedHttpData, "/Users/lichunlin/CLionProjects/webserver/version_0.1");
            FileState  fileState = fooStaticFile(sharedHttpData, basePath.c_str());
            send(sharedHttpData, fileState);
            // 如果是keep_alive else sharedHttpData将会自动析构释放clientSocket，从而关闭资源
            if (sharedHttpData->response_->keep_alive()) {
                //FIXME std::cout << "再次添加定时器  keep_alive: " << sharedHttpData->clientSocket_->fd << std::endl;
                Epoll::modfd(sharedHttpData->epoll_fd, sharedHttpData->clientSocket_->fd, Epoll::DEFAULT_EVENTS, sharedHttpData);
                Epoll::timerManager.addTimer(sharedHttpData, TimerManager::DEFAULT_TIME_OUT);
            }

        } else {
            // todo Bad Request 应该关闭定时器,(其实定时器已经关闭,在每接到一个新的数据时)
            std::cout << "Bad Request" << std::endl;
        }
    }
}

void HttpServer::fooHeader(std::shared_ptr<HttpData> httpData) {
    if (httpData->request_->mVersion == HttpRequest::HTTP_11) {
        httpData->response_->setVersion(HttpRequest::HTTP_11);
    } else {
        httpData->response_->setVersion(HttpRequest::HTTP_10);
    }
    //<string, string>
    httpData->response_->addHeader("Server", "LC WebServer");
}


// 获取Mime 同时设置path到response
void HttpServer::fooGetMime(std::shared_ptr<HttpData> httpData) {
    std::string filepath = httpData->request_->mUri;
    std::string mime;
    int pos;
//    std::cout << "uri: " << filepath << std::endl;
    // FIXME 直接将参数丢掉了，后续可以开发
    //http://www.aspxfans.com:8080/news/index.asp?boardID=5&ID=24618&page=1#name http请求URL例子  ?前为地址，后为参数
    if ((pos = filepath.rfind('?')) != std::string::npos) {
        filepath.erase(filepath.rfind('?'));
    }

    //提取mime。即 . 号后的字符
    if (filepath.rfind('.') != std::string::npos){
        mime = filepath.substr(filepath.rfind('.'));
    }
    decltype(Mime_map)::iterator it;

    //根据mine在map<string, MimeType>中找到对应值，添加到reponse_中
    if ((it = Mime_map.find(mime)) != Mime_map.end()) {
        httpData->response_->setMime(it->second);
    } else {
        httpData->response_->setMime(Mime_map.find("default")->second);
    }
    httpData->response_->setFilePath(filepath);
}

HttpServer::FileState HttpServer::fooStaticFile(std::shared_ptr<HttpData> httpData, const char *basepath) {
    struct stat file_stat;
    char file[strlen(basepath) + strlen(httpData->response_->fooFilePath().c_str()) + 1];
    strcpy(file, basepath); //复制basepath到file
    strcat(file, httpData->response_->fooFilePath().c_str());   //追加字符串到结尾

    // 文件不存在
    if (httpData->response_->fooFilePath() == "/" || stat(file, &file_stat) < 0) {
        // FIXME 设置Mime 为 html
        httpData->response_->setMime(MimeType("text/html"));
        if (httpData->response_->fooFilePath() == "/") {
            httpData->response_->setStatusCode(HttpResponse::k200Ok);
            httpData->response_->setStatusMsg("OK");
        } else {
            httpData->response_->setStatusCode(HttpResponse::k404NotFound);
            httpData->response_->setStatusMsg("Not Found");
        }
        // 废弃， 404就不需要设置filepath
        //httpData->response_->setFilePath(std::string(basepath)+"/404.html");
        //std::cout << "File Not Found: " <<   file << std::endl;
        return FIlE_NOT_FOUND;
    }
    // 不是普通文件或无访问权限
    if(!S_ISREG(file_stat.st_mode)){
        // FIXME 设置Mime 为 html
        httpData->response_->setMime(MimeType("text/html"));
        httpData->response_->setStatusCode(HttpResponse::k403forbiden);
        httpData->response_->setStatusMsg("ForBidden");
        // 废弃， 403就不需要设置filepath
        //httpData->response_->setFilePath(std::string(basepath)+"/403.html");
        std::cout << "not normal file" << std::endl;
        return FILE_FORBIDDEN;
    }

    httpData->response_->setStatusCode(HttpResponse::k200Ok);
    httpData->response_->setStatusMsg("OK");
    httpData->response_->setFilePath(file);
//    std::cout << "文件存在 - ok" << std::endl;
    return FILE_OK;
}

void HttpServer::send(std::shared_ptr<HttpData> httpData, FileState fileState) {
    char header[BUFFERSIZE];
    bzero(header, '\0');
    const char *internal_error = "Internal Error";
    struct stat file_stat;
    httpData->response_->appenBuffer(header);
    // 404
    if (fileState == FIlE_NOT_FOUND) {

        // 如果是 '/'开头就发送默认页
        if (httpData->response_->fooFilePath() == std::string("/")) {
            // 现在使用测试页面
            sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(INDEX_PAGE));
            sprintf(header, "%s%s", header, INDEX_PAGE);
        } else {
            sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(NOT_FOUND_PAGE));
            sprintf(header, "%s%s", header, NOT_FOUND_PAGE);
        }
        ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
        return;
    }

    if (fileState == FILE_FORBIDDEN) {
        sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(FORBIDDEN_PAGE));
        sprintf(header, "%s%s", header, FORBIDDEN_PAGE);
        ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
        return;
    }
    // 获取文件状态
     if (stat(httpData->response_->fooFilePath().c_str(), &file_stat) < 0) {
         sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(internal_error));
         sprintf(header, "%s%s", header, internal_error);
         ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
         return;
     }

    int filefd = ::open(httpData->response_->fooFilePath().c_str(), O_RDONLY);
    // 内部错误
    if (filefd < 0) {
        std::cout << "打开文件失败" << std::endl;
        sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(internal_error));
        sprintf(header, "%s%s", header, internal_error);
        ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
        close(filefd);
        return;
    }

    sprintf(header,"%sContent-length: %d\r\n\r\n", header, (int)file_stat.st_size);
    ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
    void *mapbuf = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, filefd, 0);
    ::send(httpData->clientSocket_->fd, mapbuf, file_stat.st_size, 0);
    munmap(mapbuf, file_stat.st_size);
    close(filefd);
    return;
err:
    sprintf(header, "%sContent-length: %d\r\n\r\n", header, (int)strlen(internal_error));
    sprintf(header, "%s%s", header, internal_error);
    ::send(httpData->clientSocket_->fd, header, strlen(header), 0);
    return;
}










