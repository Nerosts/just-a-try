#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

//class A
//{
//public:
//	int _pa;
//	friend void print(B& bb);//这个print是A的友元
//protected:
//	int _a;
//};
//
//class B :public A
//{
//public:
//	int _pb;
//	friend void print(B& bb);
//protected:
//	int _b;
//};
//
//void print(B& bb)
//{
//	cout << "公有的_pb" << bb._pa;
//	cout << "私有的_b" << bb._b;
//	cout << "公有的_pb" << bb._pb;
//	cout << "私有的_b" << bb._b;
//}

//int main()
//{
//
//	return 0;
//}

//class Person
//{
//public:
//	Person() 
//	{
//		++_count; 
//	}
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//int main()
//{
//	Person p1;
//	Person p2;
//	Student s2;
//
//	cout << Person::_count << endl;
//	cout << Student::_count << endl;
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 老师编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void test3()
//{
//	Assistant a;
//	a._name = "Nero";
//}
//
//int main()
//{
//	test3();
//	return 0;
//}

class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;

	d._b = 3;
	d._c = 4;
	d._d = 5;

	B b;
	b._a = 12;
	b._b = 13;

	B* pb = &d;//B的一个指针指向D的对象
	pb->_a++;//B的_a++

	pb = &b;
	pb->_a++;
	return 0;
}
