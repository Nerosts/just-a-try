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
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};

class Student : public Person//学生类继承于Person类
{
public:
	int _No; // 学号（学生类自己的成员变量）
};
void test1()
{
	Student stu;
	//子类对象可以赋值给父类对象/指针/引用
	Person per = stu;
	Person* pper = &stu;
	Person& rper = stu;

	//基类对象不能赋值给派生类对象
	stu = per;

	//基类的指针可以通过强制类型转换赋值给派生类的指针
	pper = &stu;
	Student * ps1 = (Student*)pper; // 这种情况转换时可以的。
	ps1->_No = 10;

	pper = &per;
	Student* ps2 = (Student*)pper; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}

int main()
{
	test1();
	return 0;
}
