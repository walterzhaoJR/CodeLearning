#include "thread_pool.h"

#include<stdio.h>
#include<stdlib.h>
#include <iostream>

namespace walter
{
	ThreadPool::ThreadPool(int threadNum)
	{
		m_is_running = true;
		m_thread_num = threadNum;

		createThreads();
	}

	ThreadPool::~ThreadPool()
	{
		stop();

		for(std::deque<Task*>::iterator iter = m_taskQueue.begin();iter != m_taskQueue.end();iter++)
		{
			delete *iter;
		}
		m_taskQueue.clear();
	}

	int ThreadPool::createThreads()
	{
		pthread_mutex_init(&m_mutex,NULL);
		pthread_cond_init(&m_cond,NULL);
		m_threads = (pthread_t*)malloc(sizeof(pthread_t) * m_thread_num);
		for(unsigned int i = 0;i<m_thread_num;i++)
		{
			pthread_create(&m_threads[i],NULL,threadFun,this);
		}

		return 0;
	}

	size_t ThreadPool::add_task(Task* task)
	{
		pthread_mutex_lock(&m_mutex);
		m_taskQueue.push_back(task);
		int size = m_taskQueue.size();
		pthread_mutex_unlock(&m_mutex);
		pthread_cond_signal(&m_cond);//发送信号，可以处理任务了

		return size;
	}

	void ThreadPool::stop()
	{
		if(!m_is_running)//正在运行的时候，不能停止
		{
			return;
		}

		m_is_running = false;
		pthread_cond_broadcast(&m_cond);

		for(unsigned int i=0;i<m_thread_num;i++)
		{
			pthread_join(m_threads[i],NULL);
		}

		free(m_threads);
		m_threads = NULL;

		pthread_mutex_destroy(&m_mutex);
		pthread_cond_destroy(&m_cond);
	}

	unsigned int ThreadPool::get_size()
	{
		pthread_mutex_lock(&m_mutex);
		int size = m_taskQueue.size();
		pthread_mutex_unlock(&m_mutex);

		return size;
	}

	Task* ThreadPool::take()//获取一个任务
	{
		Task* task = NULL;
		while(!task)
		{
			pthread_mutex_lock(&m_mutex);

			while(m_taskQueue.empty() && m_is_running)
			{
				pthread_cond_wait(&m_cond,&m_mutex);//如果线程池在运行，并且队列里边没有任务，那就阻塞等待
			}

			if(!m_is_running)
			{
				pthread_mutex_unlock(&m_mutex);

				break;
			}
			else if(m_taskQueue.empty())
			{
				pthread_mutex_unlock(&m_mutex);
				continue;
			}

			task = m_taskQueue.front();
			m_taskQueue.pop_front();
			pthread_mutex_unlock(&m_mutex);
		}

		return task;
	}

	void* ThreadPool::threadFun(void* argv)
	{
		pthread_t t = pthread_self();
		ThreadPool* pool = static_cast<ThreadPool*>(argv);

		while(pool->m_is_running)
		{
			Task* task = pool->take();
			if(!task)
			{
				printf("thread %lu will exis\n",t);
				break;
			}

			task->run();
		}

		return 0;
	}
}
