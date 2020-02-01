#include<iostream>

using namespace std;

class Base
{
public:
    int value1;
    int value2;
    Base()
    {
        value1 = 1;

    }
    Base(int _values):Base()//委托Base()构造函数
    {
        value2 = _values;
    }
};

class subClass:public Base
{
public:
    int value3;
    subClass(int value3,int value2):Base(value2)//继承父类构造
    {
        this->value3 = value3;
    }
};


/*
 *
 *当基类的虚函数被删除后，子类拥有旧的函数就不再重载该虚拟函数并摇身一变成为了一个普通的类方法，这将造成灾难性的后果。
 * C++11 引入了 override 和 final 这两个关键字来防止上述情形的发生。
 *
 *override
 * 当重载虚函数时，引入 override 关键字将显式的告知编译器进行重载，
 * 编译器将检查基函数是否存在这样的虚函数，否则将无法通过编译
 *
 * final 则是为了防止类被继续继承以及终止虚函数继续重载引入的
 *
 * */
class Test
{
public:
    virtual void foo(int){};
};

class Test2:public Test
{
public:
    virtual void foo(int) override ;//合法]
    //virtual void foo(float) override ;//非法,父类没有这个虚函数


};


//final
class BT
{
public:
    virtual void foo() final;
};

class AT final :Base
{
    //合法
};

/*
class CT:AT//非法,应为AT 已经为final的不能被继承
{

};
*/


class DT:BT
{
    //void foo();//非法,在基类中的foo()函数已经是final不能被继承的了

};

//C++11 允许显式的声明采用或拒绝编译器自带的函数
class My
{
public:
    My() = default;//显示的声明使用编译器生成的构造函数
    My& operator=(const My&my) = delete;//显示的拒绝使用编译器生成的构造
    My(int number);
};
int main()
{
    Base b(2);
    cout<<b.value1<<endl;
    cout<<b.value2<<endl;

    subClass s(10,8);
    cout<<s.value1<<endl;
    cout<<s.value2<<endl;
    cout<<s.value3<<endl;
}
