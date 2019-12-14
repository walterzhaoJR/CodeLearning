#include<iostream>
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <signal.h>
#include<string.h>

using namespace std;

void sig_handler1(int arg)
{
	cout << "pthread1 get signal" << endl;
}

void sig_handler2(int arg)
{
	cout << "pthread2 get signal" << endl;
}

void* thread_fun1(void* argv)
{
	cout << "thread_fun1" << endl;

	struct sigaction act;
	memset(&act,0,sizeof(act));
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler = sig_handler1;
	sigaction(SIGQUIT,&act,NULL);

	pthread_sigmask(SIG_BLOCK,&act.sa_mask,NULL);
	sleep(2);
}

void* thread_fun2(void* argv)
{
	cout << "thread_fun2" << endl;

	struct sigaction act;
	memset(&act,0,sizeof(act));
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_handler = sig_handler2;
	sigaction(SIGQUIT,&act,NULL);

	sleep(2);
}

int main()
{
	pthread_t p1,p2;
	int err = 0;
	int res = 0;

	if(0 != pthread_create(&p1,NULL,thread_fun1,NULL))
	{
		cout << "create thread1 error" << endl;
		return -1;
	}

	if(0 != pthread_create(&p2,NULL,thread_fun2,NULL))
	{
		cout << "creaet thread_2 error" << endl;
		return -1;
	}

	sleep(1);

	if(0 != pthread_kill(p1,SIGQUIT))
	{
		cout << "send signal to thread1 error" << endl;
	}

	if(0 != pthread_kill(p2,SIGQUIT))
	{
		cout << "send signal to thread2 error" << endl;
	}


	pthread_join(p1,NULL);
	pthread_join(p2,NULL);

	return 0;
}