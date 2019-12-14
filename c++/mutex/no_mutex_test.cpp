#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<iostream>

using namespace std;

#define err_sys(msg) \
do {perror(msg);exit(-1);} while(0)

#define err_exit(msg) \
do {fprintf(stderr,msg);exit(-1);}while(0)

int glab = 1;


void* r1(void* argv)
{
	//pthread_mutex_t* mutex = (pthread_mutex_t*)argv;
	static int count = 10;

	//while(count--)
//	{
		//pthread_mutex_lock(mutex);
//		sleep(3);
		glab++;
		cout << "r1 glab:" << glab << endl;
		//pthread_mutex_unlock(mutex);
		sleep(1);
//	}

	return (void*)"r1 finish";
}

void* r2(void* argv)
{
	//pthread_mutex_t* mutex = (pthread_mutex_t*)argv;

	static int count = 10;
//	while(count--)
//	{
		//pthread_mutex_lock(mutex);
		glab++;
		cout << "r2 glab:" << glab << endl;
		//pthread_mutex_unlock(mutex);
		sleep(1);
//	}

	return (void*)"r2 finsh";
}
int main()
{
	//pthread_mutex_t mutex;
	pthread_t t1;
	pthread_t t2;

	char* p1 = NULL;
	char* p2 = NULL;
	/*
	if(pthread_mutex_init(&mutex,NULL) < 0)
	{
		err_sys("sem_init error");
	}
	*/
	int i = 10;
	while(i--)
	{
		pthread_create(&t1,NULL,r1,NULL);
		pthread_create(&t2,NULL,r2,NULL);
	}

	//pthread_mutex_destroy(&mutex);

	pthread_join(t1,(void**)&p1);
	pthread_join(t2,(void**)&p2);

	cout << "s1:" << p1 <<endl;
	cout << "s2:" << p2 << endl;
	
	return 0;
}





















