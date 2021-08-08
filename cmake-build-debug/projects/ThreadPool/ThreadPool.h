#pragma once
#include "TaskQueue.h"

class ThreadPool
{
public:
    ThreadPool(int min, int max);
    ~ThreadPool();

    // �������
    void addTask(Task task);
    // ��ȡæ�̵߳ĸ���
    int getBusyNumber();
    // ��ȡ���ŵ��̸߳���
    int getAliveNumber();

private:
    // �������̵߳�������
    static void* worker(void* arg);
    // �������̵߳�������
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

