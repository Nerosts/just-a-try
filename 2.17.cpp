#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person 
{
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }//虚函数
};

class Child:public Person
{
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }//子类进行重写了
};

void test1()
{
	Person* p = new Person;//基类的指针
	p->BuyTicket();//调用BuyTicket

	Child ch;
	p = &ch;//现在基类的指针指向了子类
	p->BuyTicket();
}

int main()
{
	test1();
	return 0;
}