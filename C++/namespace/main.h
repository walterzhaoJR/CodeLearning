//
// Created by walter on 2018/6/15.
//

#ifndef CPPTEST_MAIN_H
#define CPPTEST_MAIN_H

#include <iostream>

using namespace std;

namespace test
{

    class Test1 {
    public:
        Test1() : age(0), name("") {}

        virtual ~Test1() {}

        void set_value(int age, std::string name) {
            this->age = age;
            this->name = name;
        }

        void print() {
            cout << "name:" << name << endl;
            cout << "age:" << age << endl;
        }

    private:
        int age;
        std::string name;
    };

}


namespace name {
    class Car
    {
    public:
        Car():name(""){}
        virtual ~Car(){}
    private:
        std::string name;
    };
}


#endif //CPPTEST_MAIN_H
