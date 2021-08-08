#include "TaskQueue.h"

TaskQueue::TaskQueue()
{
	pthread_mutex_init(&mutex_tasks,NULL);
}

TaskQueue::~TaskQueue()
{
	pthread_mutex_destroy(&mutex_tasks);
}

void TaskQueue::addTask(Task& task)
{
	pthread_mutex_lock(&mutex_tasks);
	tqueue.push(task);
	pthread_mutex_unlock(&mutex_tasks);
}

void TaskQueue::addTask(callback func, void* arg)
{
	pthread_mutex_lock(&mutex_tasks);
	Task task;
	task.function = func;
	task.arg = arg;
	tqueue.push(task);
	pthread_mutex_unlock(&mutex_tasks);
}

Task TaskQueue::takeTask()
{
	Task tmp;
	pthread_mutex_lock(&mutex_tasks);
	
	if (tqueue.size()>0)
	{
		tmp = tqueue.front();
		tqueue.pop();
	}
	pthread_mutex_lock(&mutex_tasks);
	return tmp;
}
