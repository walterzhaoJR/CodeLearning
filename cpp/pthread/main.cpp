#include<iostream>
#include<pthread.h>

using namespace std;

template <typename TYPE, void (TYPE::*_RunThread)() >  
void* _thread_t(void* param)//线程启动函数，声明为模板函数  
{     
    TYPE* This = (TYPE*)param;     
    This->_RunThread();     
    return NULL;  
}  

class MyClass  
{  
    public:    
        void _RunThread();  
        void my_test();        

    private:    
        pthread_t tid;    
};  

void MyClass::_RunThread()  
{     
    //this->DoSomeThing();  
    cout << "test" << endl;
}  

void MyClass::my_test()  
{     
    cout << "pthread" << endl;
    pthread_create(&tid, NULL, _thread_t<MyClass, &MyClass::_RunThread>, this); 
    pthread_detach(tid);
}       

int main(){


    MyClass *test = new MyClass();
    test->my_test();
}
