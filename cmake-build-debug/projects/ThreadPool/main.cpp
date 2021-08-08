#include <iostream>

#include <unistd.h>

#include "ThreadPool.h"

void taskFunc(void* arg) {
	int num = *(int*)arg;
	std::cout << "�߳�<" << pthread_self()<<">���ڹ���"<<std::endl;
	sleep(1);
}


int main()
{
	ThreadPool pool(3, 10);

	for (int i = 0; i < 100; ++i) {
		int* num = new int(i);
		pool.addTask(Task(taskFunc, num));
	}
	
	sleep(30);
	return 0;
}