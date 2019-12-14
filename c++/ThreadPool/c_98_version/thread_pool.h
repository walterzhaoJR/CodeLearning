#include <deque>
#include <string>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

namespace walter
{
	class Task//任务基类
	{
	public:
		Task(void* argv = NULL,const std::string taskName = ""):m_argv(argv),m_taskNum(taskName){}
		~Task(){}

		void setArgv(void* argv)
		{
			m_argv = argv;
		}

		virtual int run() = 0;//纯虚函数，具体的业务实现

	protected:
		void* m_argv;
		std::string m_taskNum;
	};


	class ThreadPool
	{
	public:
		ThreadPool(int pthread_num = 20);
		~ThreadPool();

		size_t add_task(Task* task);
		void stop();
		unsigned int get_size();
		Task* take();

	private:
		int createThreads();
		static void* threadFun(void* threadData);

		ThreadPool& operator=(const ThreadPool&);
		ThreadPool(const ThreadPool&);

		volatile bool		m_is_running;
		int 				m_thread_num;
		pthread_t*			m_threads;
		std::deque<Task*>	m_taskQueue;
		pthread_mutex_t 	m_mutex;
		pthread_cond_t		m_cond;
	};
}
