
#include "ThreadPool.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
ThreadPool::ThreadPool(int min, int max)
{
	task_queue = new TaskQueue;

	do {
		min_thread = min;
		max_thread = max;
		busy_thread = 0;
		live_thread = 0;

		threadIDs = new pthread_t[max_thread];
		if (threadIDs = nullptr) {
			std::cout << "malloc for threads failed" << std::endl;
			break;
		}
		memset(threadIDs, 0 , max_thread * sizeof(pthread_t));
		pthread_mutex_init(&mutex_pool,NULL);
		pthread_cond_init(&not_empty,NULL);

		for (int i = 0; i < min_thread; ++i) {
			pthread_create(&threadIDs[i], NULL, worker, this);
			std::cout << "创建线程， id = " << std::to_string(threadIDs[i]) << std::endl;
		}
		pthread_create(&managerID, NULL, manager, this);
	} while (0);
}

ThreadPool::~ThreadPool()
{
	shutdown = true;
	pthread_join(managerID, NULL);
	for (int i = 0; i < live_thread; ++i) {
		pthread_cond_signal(&not_empty);
	}
	if (task_queue) delete task_queue;
	if (threadIDs) delete[] threadIDs;
	pthread_mutex_destroy(&mutex_pool);
	pthread_cond_destroy(&not_empty);

}

void ThreadPool::addTask(Task task)
{
	if (shutdown) return;
	task_queue->addTask(task);
	pthread_cond_signal(&not_empty);
}

int ThreadPool::getBusyNumber()
{
	int ret{ 0 };
	pthread_mutex_lock(&mutex_pool);
	ret = this->busy_thread;
	pthread_mutex_unlock(&mutex_pool);
	return ret;
}

int ThreadPool::getAliveNumber()
{
	int ret{ 0 };
	pthread_mutex_lock(&mutex_pool);
	ret = this->live_thread;
	pthread_mutex_unlock(&mutex_pool);
	return ret;
}

void* ThreadPool::worker(void* arg)
{
	auto* pool = static_cast<ThreadPool*>(arg);

	while(true)
	{
		pthread_mutex_lock(&pool->mutex_pool);
		while (pool->task_queue->getTaskNum() == 0)
		{
			std::cout << "线程" << std::to_string(pthread_self()) << "等待......" <<std::endl;
			pthread_cond_wait(&pool->not_empty, &pool->mutex_pool);

			if (pool->exit_thread > 0) {
				pool->exit_thread--;
				if (pool->live_thread > pool->min_thread) {
					pool->live_thread--;
					pthread_mutex_unlock(&pool->mutex_pool);
					pool->threadExit();
				}
			}
		}

		if (pool->shutdown) {
			pthread_mutex_unlock(&pool->mutex_pool);
			pool->threadExit();
		}

		auto task = pool->task_queue->takeTask();
		pool->busy_thread++;
		pthread_mutex_unlock(&pool->mutex_pool);

		task.function(task.arg);
		delete task.arg;
		task.arg = nullptr;
		std::cout<< "线程" << std::to_string(pthread_self()) << "任务处理结束" << std::endl;
		pthread_mutex_lock(&pool->mutex_pool);
		pool->busy_thread--;		
		pthread_mutex_unlock(&pool->mutex_pool);
	}
	return nullptr;
}

void* ThreadPool::manager(void* arg)
{
	auto* p = static_cast<ThreadPool*>(arg);
	while (!p->shutdown)
	{
		sleep(5);
		pthread_mutex_lock(&p->mutex_pool);
		int live_num = p->live_thread;
		int busy_num = p->busy_thread;
		int queue_size = p->task_queue->getTaskNum();
		pthread_mutex_unlock(&p->mutex_pool);

		const int NUMBER = 2;

		if (queue_size > live_num && live_num < p->max_thread) {
			pthread_mutex_lock(&p->mutex_pool);
			int num = 0;
			for (int i = 0; i < p->max_thread && num < NUMBER && p->live_thread < p->max_thread; ++i)
			{
				if (p->threadIDs[i] == 0) {
					pthread_create(&p->threadIDs[i], NULL, worker, p);
					num++;
					p->live_thread++;
				}
			}
			pthread_mutex_unlock(&p->mutex_pool);
		}
		if (busy_num * 2 < live_num && live_num > p->min_thread)
		{
			pthread_mutex_lock(&p->mutex_pool);
			p->exit_thread = NUMBER;
			pthread_mutex_unlock(&p->mutex_pool);
			for (int i = 0; i < NUMBER; ++i)
			{
				pthread_cond_signal(&p->not_empty);
			}
		}
	}
	return nullptr;
}

void ThreadPool::threadExit()
{
	pthread_t tid = pthread_self();
	for (int i = 0; i < max_thread; ++i)
	{
		if (threadIDs[i] == tid)
		{
			std::cout << "threadExit() function: thread "
				<< std::to_string(pthread_self()) << " exiting..." << std::endl;
			threadIDs[i] = 0;
			break;
		}
	}
	pthread_exit(NULL);
}
