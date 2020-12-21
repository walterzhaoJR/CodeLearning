#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

__thread int t_value = 10;
int value = 20;

void fun1()
{
    cout << "fun1 t_value:" << ++t_value << " value:" << ++value << endl;
}

void fun2()
{
    sleep(1);//等待thread1 先执行
    cout << "fun2 t_value:" << ++t_value << " value:" << ++value << endl;
}

int main()
{
    std::thread t1 = std::thread(fun1);
    std::thread t2 = std::thread(fun2);
    t1.join();
    t2.join();

    /*
    result:
    fun1 t_value:11 value:21
    fun2 t_value:11 value:22
    说明 __thread 类型的变量，每个线程独有一份.
    */
    return 0;
}