//
// Created by peterwarlg on 2021/2/1 3:50 PM.
//

//#ifndef WEBSERVER_SOCKET_H
//#define WEBSERVER_SOCKET_H

#pragma once

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <memory>


class ClientSocket;

void setReusePort(int fd);


class ServerSocket {

public:
    ServerSocket(int port = 8080, const char *ip = nullptr);

    ~ServerSocket();

    void fooBind();

    void fooListen();

    void fooClose();

    int fooAccept(ClientSocket &clientSocket) const;

public:
    sockaddr_in mAddr;
    int listen_fd;
    int epoll_fd;
    int mPort;
    const char *mIp;

};

class ClientSocket {

public:
    ClientSocket() { fd = -1; };

    void close();

    ~ClientSocket();

    socklen_t mLen;
    sockaddr_in mAddr;
    int fd;
};
//#endif //WEBSERVER_SOCKET_H
