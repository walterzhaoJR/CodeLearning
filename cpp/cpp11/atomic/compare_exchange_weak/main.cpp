/*
https://blog.csdn.net/syzcch/article/details/8075830
*/
#include <atomic>
#include <iostream>


using namespace std;

std::atomic<int> ai;

int tst_val = 4;
int new_val = 5;
bool exchanged = false;

void valsout()
{
    std::cout << "ai= " << ai
              << "  tst_val= " << tst_val
              << "  new_val= " << new_val
              << "  exchanged= " << std::boolalpha << exchanged
              << "\n";
}

int main()
{
    ai = 3;
    valsout();

    // tst_val != ai   ==>  tst_val 被修改
    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    valsout();

    // tst_val == ai   ==>  ai 被修改
    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    valsout();

    cout << "compare_exchange_weak\n";
    ai = 3;
    tst_val = 4;
    new_val = 5;
    valsout();
    do//compare_exchange_weak 有假的false返回，一般需要while循环获得true
    {
        exchanged = ai.compare_exchange_weak(tst_val, new_val);
        valsout();
    } while (!exchanged);

    return 0;
}