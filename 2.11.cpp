#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

//class A
//{
//public:
//	int _pa;
//	friend void print(B& bb);//���print��A����Ԫ
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
//	cout << "���е�_pb" << bb._pa;
//	cout << "˽�е�_b" << bb._b;
//	cout << "���е�_pb" << bb._pb;
//	cout << "˽�е�_b" << bb._b;
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
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//
//int Person::_count = 0;
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
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
//	string _name; // ����
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ��ʦ���
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
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

	B* pb = &d;//B��һ��ָ��ָ��D�Ķ���
	pb->_a++;//B��_a++

	pb = &b;
	pb->_a++;
	return 0;
}
