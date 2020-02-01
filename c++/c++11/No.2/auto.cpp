#include<iostream>
#include<vector>
#include<iterator>

using namespace std;


int main()
{
    auto i = 10;
    vector<int > array;
    array.push_back(100);
    array.push_back(200);

    for(vector<int >::iterator iter = array.begin();iter!=array.end();iter++)
    {

    }

    //auto
    for(auto iter=array.begin();iter!=array.end();iter++);

    //auto不能用于函数传递参数,考虑重载的要使用模板
    //decltype()关键字是为了解决 auto 关键字只能对变量进行类型推导的缺陷而出现的

    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    //cout<<add(1,5.5)<<endl;



}


//看一个加法的例子
template <typename R,typename T,typename Y>
R add(T x,Y y)
{
    return x+y;
};

//C++11 还引入了一个叫做尾返回类型（trailing return type），利用 auto 关键字将返回类型后置
template <typename T ,typename Y>
auto add(T x,Y y) -> decltype(x+y)
{
    return x+y;
};
