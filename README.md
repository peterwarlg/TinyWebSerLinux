# TinyWebSerLinux

### Linux下的高性能web服务器

### 开发环境 ：

* Ubuntu20.04
* Clion
* g++ 3.10
* cmake
* 压测：Wenbench

### 编译及运行

```shell
cd cmake-build-debug
cmake .
make
./webserver -p [端口号] -t [线程数量] -d [守护进程模式] -r [pages所在路径]
```

* 单进程＋Reactor+非阻塞方式运行
  
* **状态机解析HTTP请求，目前支持 HTTP GET、HEAD方法**
* **添加定时器支持HTTP长连接，定时回调handler处理超时连接**
* **使用 priority queue 实现的最小堆结构管理定时器，使用标记删除，以支持惰性删除，提高性能**
* **使用epoll + 非阻塞IO + 边缘触发(ET) 实现高并发处理请求，使用Reactor编程模型**
* **epoll使用EPOLLONESHOT保证一个socket连接在任意时刻都只被一个线程处理**
* **使用线程池提高并发度，并降低频繁创建线程的开销**
* **同步互斥的介绍**
* **使用RAII手法封装互斥器(pthrea_mutex_t)、 条件变量(pthread_cond_t)等线程同步互斥机制，使用RAII管理文件描述符等资源**
* **使用shared_ptr、weak_ptr管理指针，防止内存泄漏**
