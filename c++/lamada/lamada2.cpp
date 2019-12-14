#include<iostream>

using namespace std;

int main(){
    int i = 100;
    auto fun = [](int i){
        i += 10;
        cout << "i+10=" << i << endl;
    };
    fun(i);
    
}
