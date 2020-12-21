#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include "thread_pool.h"

using namespace std;

class DoTask:public walter::Task
{
public:
	DoTask(){}

	virtual int run()
	{
		printf("thread[%lu]:%s\n",pthread_self(),(char*)this->m_argv);
		sleep(1);

		return 0;
	}
};


int main()
{
	char str[] = "hello walter";

	DoTask task;
	task.setArgv((void*)str);

	walter::ThreadPool threadPool(5);

	for(unsigned int i=0;i<20;i++)
	{
		threadPool.add_task(&task);
	}

	while(1)
	{
		printf("thread are still %d tasks need to process\n",threadPool.get_size());
		if(0 == threadPool.get_size())
		{
			threadPool.stop();
			cout << "now i will exit from main\n";
			exit(0);
		}

		sleep(2);
	}

	return 0;
}
