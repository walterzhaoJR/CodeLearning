#include<iostream>

using namespace std;



int sum(int a,int b)//回调函数
{
	return a+b;
}

int sub(int a,int b)
{
	return a - b;
}

int calc(int a,int b,int (*fun)(int,int))
{
	return fun(a,b);
}


int main()
{
	int a = 10;
	int b = 20;

	cout << calc(a,b,sum) << endl;
	cout << calc(a,b,sub) << endl;


	return 0;
}
