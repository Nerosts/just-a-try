#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

//class Person
//{
//protected:
//	string _name = "Neor"; // ����
//	int _id = 111;//���֤��
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "ѧ��:" << _id << endl;
//		cout << "���֤��" << Person::_id << endl;
//	}
//protected:
//	int _id = 888; // ѧ��
//};
//
//void test1()
//{
//	Student s1;
//	s1.Print();
//};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "���캯��Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "��������Person(const Person& p)" << endl;
	}

	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;

		return *this;
	}

	~Person()
	{
		cout << "��������~Person()" << endl;
	}
protected:
	string _name; // ����
};

class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)//��û��Ĭ�Ϲ��캯��ʱ����Ҫ����������ʾ����
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)//�����Ҫ�Լ�������ʾ���ã���ô�õ����൱�и���Ĳ����أ����ýض�
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);//ֱ��operator =(s)����Ϊ���أ�һֱ����
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};

void test2()
{
	Student s1("Nero", 18);
}

int main()
{
	test2();
	return 0;
}