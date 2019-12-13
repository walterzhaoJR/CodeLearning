#include <iostream>
#include <memory>

using namespace std;

int main()
{
  shared_ptr<int> p1(new int(10));
  cout << "p1 count:" << p1.use_count() << endl;
  /*case 1
  shared_ptr<int> p2(p1);
  cout << "p1 count:" << p1.use_count() << endl;
  cout << "p2 count:" << p2.use_count() << endl;
  */
  
  /*case 2
  */
  weak_ptr<int> p3(p1);
  cout << "p1 count:" << p1.use_count() << endl;
  cout << "p3 count:" << p3.use_count() << endl;
  return 0;
}
