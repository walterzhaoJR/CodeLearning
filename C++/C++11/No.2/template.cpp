#include<iostream>
#include<vector>
#include<map>
#include<string>


using namespace std;

//using 对typedef功能的扩充和简化
//C++11 引入了外部模板，扩充了原来的强制编译器在特定位置实例化模板的语法，
// 使得能够显式的告诉编译器何时进行模板的实例化：

//template class vector<bool>;            //强制实例化
//extern template class vector<double>;   //不在变编译文件中实例化模板

//using 对typedef使用的简化
typedef int(*process)(void*);//定义了一个返回值类型为int的,参数为void*的函数指针类型,名字为process
using process = int(*)(void*);//同上


//typedef 可以为类型定义一个新的名称，但是却没有办法为模板定义一个新的名称。因为，模板不是类型。

template< typename T, typename U, int value>
class SuckType {
public:
    T a;
    U b;
    SuckType():a(value),b(value){}
};
/*
template< typename U>
typedef SuckType<std::vector<int>, U, 1> NewType; // 不合法
*/
//使用using
template <typename T>
using NewType = SuckType<int,T,1>;//合法


//默认模板参数
//我们可能定义了一个加法函数：
template <typename T,typename Y>
auto add(T x,Y y)-> decltype(x+y)
{
    return x+y;
};

//或许在使用的时候,每次都要指定模板参数的类型
//C++支持指定模板参数的:
template <typename T = int,typename Y = int>
auto sub(T x,Y y)-> decltype(x-y)
{
    return x-y;
};


/*
 *
 * 变长参数模板

模板一直是 C++ 所独有的黑魔法（一起念：Dark Magic）之一。
 在 C++11 之前，无论是类模板还是函数模板，都只能按其指定的样子，
 接受一组固定数量的模板参数；而 C++11 加入了新的表示方法，
 允许任意个数、任意类别的模板参数，同时也不需要再定义时将参数的个数固定。

 * */

template <typename... Ts>
class Magic{};

//模板类Magic的对象,可以接受不限个数的typename作为模板的形式参数:
class Magic<> t0;
class Magic<int > tint;
class Magic<int,
        vector<int>,
                map<string,vector<int>>> t3;



/*
 * 既然是任意形式，所以个数为0的模板参数也是可以的：class Magic<> nothing;。

如果不希望产生的模板参数个数为0，可以手动的定义至少一个模板参数：

template<typename Require, typename... Args> class Magic;
 *
 * */

//变长参数模板也能被直接调整到到模板函数上。
//我们可以使用sizeof来确定变成参数个数

template<typename... Argc>
void func1(Argc... argcs)
{
    cout<<sizeof...(argcs)<<endl;
}

//其次，对参数进行解包，到目前为止还没有一种简单的方法能够处理参数包，但有两种经典的处理手法：
/*
 *1. 递归模板函数

递归是非常容易想到的一种手段，也是最经典的处理方法。这种方法不断递归的向函数传递模板参数，进而达到递归遍历所有模板参数的目的：

#include <iostream>
template<typename T>
void printf(T value) {
    std::cout << value << std::endl;
}
template<typename T, typename... Args>
void printf(T value, Args... args) {
    std::cout << value << std::endl;
    printf(args...);
}
int main() {
    printf(1, 2, "123", 1.1);
    return 0;
}
 *
 * */

/*
 *2. 初始化列表展开

这个方法需要之后介绍的知识，读者可以简单阅读以下，将这个代码段保存，在后面的内容了解过了之后再回过头来阅读此处方法会大有收获。
递归模板函数是一种标准的做法，但缺点显而易见的在于必须定义一个终止递归的函数。

这里介绍一种使用初始化列表展开的黑魔法：

// 编译这个代码需要开启 -std=c++14
template<typename T, typename... Args>
auto print(T value, Args... args) {
    std::cout << value << std::endl;
    return std::initializer_list<T>{([&] {
        std::cout << args << std::endl;
    }(), value)...};
}
int main() {
    print(1, 2.1, "123");
    return 0;
}
 *
 *
 *
 * 在这个代码中，额外使用了 C++11 中提供的初始化列表以及 Lambda 表达式的特性（下一节中将提到），而 std::initializer_list 也是 C++11 新引入的容器（以后会介绍到）。

通过初始化列表，(lambda 表达式, value)... 将会被展开。由于逗号表达式的出现，首先会执行前面的 lambda 表达式，完成参数的输出。唯一不美观的地方在于如果不使用 return 编译器会给出未使用的变量作为警告。

事实上，有时候我们虽然使用了变参模板，却不一定需要对参数做逐个遍历，我们可以利用 std::bind 及完美转发等特性实现对函数和参数的绑定，从而达到成功调用的目的。

 * */

template <typename T>
void print(T value)
{
    cout<<"#1: "<<value<<endl;
}

template <typename T,typename ...Argcs>
void print(T value,Argcs... argcs)
{
    cout<<"#2: "<<value<<endl;
    print(argcs...);
};

int main()
{
    //在传统 C++ 的编译器中，>>一律被当做右移运算符来进行处理。但实际上我们很容易就写出了嵌套模板的代码：
    vector<vector<int > > arrayi;//C++11之前非法
    vector<vector<double >> arrayd;//C++11中合法

    //测试变成参数函数额参数个数
    func1();
    func1(1,"");
    func1(2.2);

    //测试变成模板参数捷豹
    print(1,2,"123",4.4);



    return 0;
}
