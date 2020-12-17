#include<iostream>
#include<vector>
#include<initializer_list>


using namespace std;

//初始化列表
//C++11 首先把初始化列表的概念绑定到了类型上，并将其称之为 std::initializer_list，
//允许构造函数或其他函数像参数一样使用初始化列表，
// 这就为类对象的初始化与普通数组和 POD(plain old data，没有构造、析构和虚函数的类或结构体)
// 的初始化方法提供了统一的桥梁

class Magic{
public:
    //这种构造函数被叫做初始化列表构造函数，具有这种构造函数的类型将在初始化时被特殊关照。
    Magic(initializer_list<int> list){}
};

Magic magic = {1,2,3,4,5};
vector<int > vec = {1,2,3,4,5,6};

//初始化列表除了用在对象构造上，还能将其作为普通函数的形参，例如：
void func(initializer_list<int > list)
{
    return ;
}

//C++11 提供了统一的语法来初始化任意的对象，例如：
struct A
{
    int a;
    float b;
};

struct B
{
    B(int _a,float _b):a(_a),b(_b){}

private:
    int a;
    int b;
};


int main()
{
    func({1,2,3,4,5});//注意传递参数的形势
    //统一的初始化语法
    A a{1,1.1};
    B b{2,2.2};
}
