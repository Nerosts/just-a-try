#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//class A
//{
//public:
//	int _public;
//protected:
//	int _protected;
//private:
//	int _private;
//};
//
//class B :public A
//{
//public:
//	void print_public()
//	{
//		cout << _public << endl;
//	}
//	void print_protected()
//	{
//		cout << _protected << endl;
//	}
//	void print_private()
//	{
//		cout << _private << endl;
//	}
//};

class Person
{
protected:
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};

class Student : public Person//ѧ����̳���Person��
{
public:
	int _No; // ѧ�ţ�ѧ�����Լ��ĳ�Ա������
};
void test1()
{
	Student stu;
	//���������Ը�ֵ���������/ָ��/����
	Person per = stu;
	Person* pper = &stu;
	Person& rper = stu;

	//��������ܸ�ֵ�����������
	stu = per;

	//�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pper = &stu;
	Student * ps1 = (Student*)pper; // �������ת��ʱ���Եġ�
	ps1->_No = 10;

	pper = &per;
	Student* ps2 = (Student*)pper; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	ps2->_No = 10;
}

int main()
{
	test1();
	return 0;
}
