#include<iostream>

using namespace std;

int main(){

    int i = 10;
    auto fun = [&](){
    
        cout << "lamada i:" << i << endl;
        i += 10;
        cout << "lamada new i:" << i << endl;
    };

    fun();

}
