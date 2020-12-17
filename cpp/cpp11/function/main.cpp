#include <iostream>
#include <functional>

using namespace std;

struct Foo
{
  Foo(int num) : num_(num) {}
  void print_add(int i) const {
    cout << "num+i:" << num_ + i << endl;
  }

  int num_;
};

void print_num(int i)
{
  cout << "i:" << i << endl;
}

struct PrintNum
{
  void operator()(int i) const {
    cout << "PrintNum i:" << i << endl;
  }
};

int main()
{
  //存储自由函数
  std::function<void(int)> f1 = print_num;
  f1(-9);

  //存储lambda
  std::function<void()> f2 = []() {
    cout << "lambda:\t";
    print_num(99);
  };
  f2();

  //存储bind调用结果
  std::function<void()> f3 = std::bind(print_num, 123);
  f3();

  std::function<void(int)> f4 = std::bind(print_num, std::placeholders::_1);
  f4(0);

  //存储到成员函数调用
  std::function<void(const Foo&, int i)> f5 = &Foo::print_add;
  const Foo foo(911);
  f5(foo, 1);
  f5(922 ,1);
  
  //存储到数据成员访问的调用
  std::function<int(const Foo&)> f6 = &Foo::num_;
  const Foo foo2(234);
  cout << "Foo num:" << f6(foo2) << endl;
  
  //存储到成员函数到对象的调用
  using std::placeholders::_1;
  std::function<void(int)> f7 = std::bind(&Foo::print_add, foo2, _1);
  f7(2);
  
  //存储到成员函数到对象指针的调用
  std::function<void(int)> f8 = bind(&Foo::print_add, &foo2, _1);
  f8(3);
  
  //存储到函数对象的调用
  std::function<void(int)> f9 = PrintNum();
  f9(1111);

  return 0;
}
