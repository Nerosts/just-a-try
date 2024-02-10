#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>

using namespace std;

//class Person
//{
//protected:
//	string _name = "Neor"; // 姓名
//	int _id = 111;//身份证号
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "学号:" << _id << endl;
//		cout << "身份证号" << Person::_id << endl;
//	}
//protected:
//	int _id = 888; // 学号
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
		cout << "构造函数Person()" << endl;
	}

	Person(const Person& p)
		: _name(p._name)
	{
		cout << "拷贝构造Person(const Person& p)" << endl;
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
		cout << "析构函数~Person()" << endl;
	}
protected:
	string _name; // 姓名
};

class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)//当没有默认构造函数时，就要这样进行显示调用
		, _num(num)
	{
		cout << "Student()" << endl;
	}

	Student(const Student& s)
		: Person(s)//如果想要自己进行显示调用，怎么得到子类当中父类的部分呢？利用截断
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}

	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);//直接operator =(s)会因为隐藏，一直调用
			_num = s._num;
		}
		return *this;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
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