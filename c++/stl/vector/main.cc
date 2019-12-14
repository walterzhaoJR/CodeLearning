#include <iostream>
#include "td_vector.h"

using namespace std;

int main(){

    cout << "a" << endl;
    TDVector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    for(auto i = v.Begin();i < v.End();i++){
      cout << *i << endl;
    }

    cout << "pop" << endl;
    v.PopBack();

    for(auto i = v.Begin();i < v.End();i++){
      cout << *i << endl;
    }
    return 0;
}
