# TinyWebSerLinux

### Linux下的简单web服务器

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

