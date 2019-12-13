//
// Created by walter on 2018/6/15.
//

#include "main.h"
#include <iostream>

using namespace std;
using namespace test;
using namespace name;


int main()
{
    cout << "Test" << endl;
    Test1* test = new Test1();
    test->set_value(10,"walter");
    test->print();

    Car* car = new Car();
}
