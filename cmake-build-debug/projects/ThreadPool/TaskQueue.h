#pragma once
#include <queue>
#include <pthread.h>


using callback = void(*)(void*);
struct Task
{
	Task()
	{
		function = nullptr;
		arg = nullptr;
	}
	Task(callback func, void* arg)
	{
		function = func;
		this->arg = arg;
	}
	callback function;
	void* arg;
};

class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();

	void addTask(Task& task);
	void addTask(callback func, void* arg);
	Task takeTask();
	inline int getTaskNum() { return tqueue.size(); }

private:
	pthread_mutex_t mutex_tasks;
	std::queue<Task> tqueue;
};

