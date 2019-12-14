#include<iostream>
#include<vector>
#include<iterator>


using namespace std;

//  C++11引人了迭代区间的概念
int main()
{
    int  array[]={1,2,3,4,5};
    for(auto &x : array)
    {
        //cout<<x<<endl;
    }

    //iterator的便利也非常简单
    vector<int > vec;

    for(auto &x:array)
    {
        vec.push_back(x);
    }

    for(vector<int >::iterator iter = vec.begin();iter!=vec.end();iter++)
    {
        //cout<<*iter<<endl;
    }

    //使用迭代区间
    for(auto &x:vec)
    {
        cout<<x<<endl;
    }
}
