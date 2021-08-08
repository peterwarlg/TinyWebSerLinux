#pragma once
#include "TaskQueue.h"

class ThreadPool
{
public:
    ThreadPool(int min, int max);
    ~ThreadPool();

    // 添加任务
    void addTask(Task task);
    // 获取忙线程的个数
    int getBusyNumber();
    // 获取活着的线程个数
    int getAliveNumber();

private:
    // 工作的线程的任务函数
    static void* worker(void* arg);
    // 管理者线程的任务函数
    static void* manager(void* arg);
    void threadExit();


private:
	TaskQueue* task_queue;

	pthread_t managerID;
	pthread_t* threadIDs;

	int min_thread;
	int max_thread;
	int busy_thread;
	int live_thread;
	int exit_thread;

	pthread_mutex_t mutex_pool;
	pthread_cond_t not_empty;

	bool shutdown = false;
};

