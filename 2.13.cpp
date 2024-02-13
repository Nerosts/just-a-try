#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	virtual void fun1()
	{
		cout << "Afun1" << endl;
	}
protected:
	int _a;
};

class B:public A
{
public:
	void fun1()
	{
		cout << "Bfun1" << endl;
	}
protected:
	int _b;
};

int main()
{
	A* a=new A;
	a->fun1();
	B b;
	a = &b;
	a->fun1();
	return 0;
}