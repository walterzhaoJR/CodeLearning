#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

using namespace std;

//case 2
class Test
{
public:
  Test(int a)
  : a_(a) {}
  Test() { a_ = 0; }
  ~Test() { cout << "destruct Test" << endl; }
  void MyDelete() { cout << "walter destruct Test" << endl; }//自定义的释放器

private:
  int a_;
};

void outDelete(Test* t)
{
  t->MyDelete();
}
//end case 2

//case 3
class deleter
{
public:
  deleter()
  : a_(0) {}
  template <class T>
  void operator()(T* p) {
    cout << "walter delete " << ++a_ << endl;
    delete p;
  }
private:
  int a_;
};
//end case 3

int main()
{
  /*case 1
  std::unique_ptr<string> p1(new string("walter\n"));
  //std::unqiue_ptr<string> p2(p1); //error 不支持拷贝

  cout << "p1:" << *p1;
  
  std::unique_ptr<string> p3(new string("bob\n"));
  p1.reset(p3.release());//将p3置空返回指针，reset释放p1原来的内存
  cout << "p3 -> p1:" << *p1;
  cout << "p3:" << *p3;
  */
  
  /*case 2
  unique_ptr<Test, decltype(outDelete)*> p(new Test(1), outDelete);//指定释放器
  */

  /*case 3
  
  */
  //case 3.1
  //unique_ptr<int, deleter> p1(new int);
  //unique_ptr 保存一个指针，当他自身被销毁时(例如线程控制流离开unique_ptr的作用域)，使用关联的释放器(deleter)释放所指向的对象
  //释放器又是什么呢？当一个unique_ptr被销毁，就会调用其自己的释放器销毁所拥有的对象。
  //deleter_type& get_deleter() noexcept;
  //const deleter_type& get_deleter() const noexcept;
  //unique_ptr<int, deleter> p2(new int, p1.get_deleter());
  //case 3.2
 // p3 and p4 share the deleter "del" (deleter type is a reference!): 
  deleter del;
  unique_ptr<int, deleter&> p3(new int, del);
  unique_ptr<int, deleter&> p4(new int, p3.get_deleter());
  return 0;
}
