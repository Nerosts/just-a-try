#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "Nero";
	int _age = 18;
};

class Teacher :public Person//公有继承
{
protected:
	int _jobid;//老师的工号
};

class Student :public Person
{
protected:
	int _stuid;//学生的学号
};

int main()

{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}