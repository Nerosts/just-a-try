#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//
//	return 0;
//}

//﻿class A
//{
//public:
//  void f() 
//  { 
//	  out << "A::f()" << endl;
//  }
//
//  int a;
//
//};

//class B : public A
//
//{
//
//public:
//
//	void f(int a) { cout << "B::f()" << endl; }
//
//	int a;
//
//};

#include<iostream>
using namespace std;
class A
{
public:
	A()//无参构造
	{
		count++;
	}
	A(A& a)//拷贝构造
	{
		count++;
	}

	static int count;//类内声明，属于整体（公有）
	int a;
	int b;
};
int A::count = 0;//类外定义，就类似于成员函数声明和定义分离

int main()
{
	A aa;
	cout << sizeof(A) << endl;
}

