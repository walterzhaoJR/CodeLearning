#include <iostream>
#include <future>
#include <thread>
#include <unistd.h>
#include <queue>
#include <random>
#include <chrono>

using namespace std;

std::atomic<int> work_index(-1);
int total = 20;

int test()
{
  work_index++;
  if (work_index > total) {
    cout << "finish" << endl;
    return 0;
  }

  std::uniform_int_distribution<int> dis1(0, 15);
  std::default_random_engine random(time(NULL));
  int x = dis1(random);
  cout << "[start] sleep:" << x << endl;
  sleep(x);
  cout << "[end] sleep:" << x << endl;
  return 0;
}


void task_warp()
{
  while (true) {
    work_index++;
    cout << "work_index:" << work_index << endl;
    if (work_index > total) {
      cout << "work will finish" << endl;
      break;
    }

    std::future<int> f = std::async(std::launch::async, test);
    f.wait();
    int ret = f.get();
    if (ret != 0) {
      cout << "task fail" << endl;
      break;
    }
  }
}

int main()
{
  std::atomic<int> num(-1);
  int ret = num.fetch_add(1, std::memory_order_relaxed);
  cout << "num:" << ret << endl;
  std::thread t[10];
  for (int i = 0; i < 10; i++) {
    t[i] = std::thread(task_warp);
  }

  for (int i = 0 ;i < 10; i++) {
    t[i].join();
  }

  cout << "finsih" << endl;


  // std::uniform_int_distribution<int> dis1(0, 15);
  // std::default_random_engine random(time(NULL));
  // std::queue<std::shared_future<int>> fs;

  // for (int i = 0; i < 3; i++) {
  //   std::future<int> f = std::async(std::launch::async, test, dis1(random));
  //   fs.push(f.share());
  //   sleep(1);
  // }

  // std::future_status status;
  // std::chrono::milliseconds span(100);
  // uint64_t count = 0;

  // while (!fs.empty()) {
  //   std::shared_future<int> f = fs.front();
  //   status = f.wait_for(span);
  //   count++;
  //   if (0 == count % 10) {
  //      cout << "time:" << count / 10 << " thread_num:" << thread_num << endl;
  //   }
   
  //    switch (status) {
  //   case std::future_status::deferred:
  //     std::cout << "deferred\n";
  //     fs.pop();
  //     fs.push(f);
  //     break;
  //   case std::future_status::timeout:
  //     // std::cout << "timeout\n";
  //     fs.pop();
  //     fs.push(f);
  //     break;
  //   case std::future_status::ready:
  //     std::cout << "ready! " << count / 10;
  //     cout << "return:" << f.get() << endl;
  //     fs.pop();
  //     if (work_index < total && work_index < 3) {
  //       std::future<int> f = std::async(std::launch::async, test, dis1(random));
  //       fs.push(f.share());
  //     }
  //     break;
  //   }
  // }

    // // future from a packaged_task
    // std::packaged_task<int()> task([]{ return 7; }); // wrap the function
    // std::future<int> f1 = task.get_future();  // get a future
    // std::thread t(std::move(task)); // launch on a thread

    
    // std::queue<std::shared_future<int>> fs;

  // std::future<int> f = std::async(std::launch::async, test, 1, 10);
  // std::shared_future<int> fs = f.share();
  // std::future_status status;
  // std::chrono::seconds span(1);

  // do {
  //     status = fs.wait_for(span);
  //       switch(status) {
  //           case std::future_status::deferred: std::cout << "deferred\n"; break;
  //           case std::future_status::timeout: std::cout << "timeout\n"; break;
  //           case std::future_status::ready: std::cout << "ready!" << fs.get() << endl; break;
  //       }
  //   } while (status != std::future_status::ready);

    // for (int i = 0; i < 10; i++) {
    //   int time = dis1(random);
    //   std::future<int> f = std::async(std::launch::async, test, i, time);
    //   fs.push(f.share());
    // }

    // for (int i = 0 ; i < 10; i++) {
    //   std::shared_future<int> f = fs.front();
    //   f.wait();
    //   cout << f.get() << endl;
    //   fs.pop();
    // }

    //
    // // future from an async()
    // for (int i = 0; i < 10; i++) {
    //   
    //   fs.push(f);
    // }

    // for (const auto& one : fs) {

    // }

    // f.wait();
    // std::cout << "Done!\nResults are: " << f.get() << '\n';
    // std::cout << "Done!\nResults are: "
    //           << f1.get() << ' ' << f2.get() << '\n';
    // t.join();
}