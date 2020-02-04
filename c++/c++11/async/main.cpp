#include <iostream>
#include <future>

using namespace std;

int main()
{
#if 0
  std::future<int> f1 = std::async(std::launch::async, [](){
    return 8;
  });

  cout << f1.get() << endl;
#endif

#if 0
  std::future<void> f2 = std::async(std::launch::async, [](){
    cout << 8 << endl;
  });

  f2.wait();
#endif

#if 1
  std::future<int> f3 = std::async(std::launch::async, [](){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return 8;
  });

  std::cout << "waiting..." << endl;
  std::future_status status;

  do {
    status = f3.wait_for(std::chrono::seconds(1));
    if (status == std::future_status::deferred) {
      cout << "deferred" << endl;
    } else if (status == std::future_status::timeout) {
      cout << "timeout" << endl;
    } else if (status == std::future_status::ready) {
      cout << "ready" << endl;
    }
  } while(status != std::future_status::ready);

  cout << "result is " << f3.get() << endl;
#endif
  return 0;
}
