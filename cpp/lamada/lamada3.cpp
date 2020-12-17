#include<iostream>

using namespace std;

int main(){

    int i = 100;
    auto fun = [=](){// [=] 表明将外部的所有变量拷贝一份到该函数内部
    
        cout << "i:" << i << endl;
    };

    fun();
}
