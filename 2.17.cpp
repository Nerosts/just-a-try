#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person 
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }//�麯��
};

class Child:public Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }//���������д��
};

void test1()
{
	Person* p = new Person;//�����ָ��
	p->BuyTicket();//����BuyTicket

	Child ch;
	p = &ch;//���ڻ����ָ��ָ��������
	p->BuyTicket();
}

int main()
{
	test1();
	return 0;
}