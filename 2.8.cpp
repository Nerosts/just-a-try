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

class Teacher :public Person//���м̳�
{
protected:
	int _jobid;//��ʦ�Ĺ���
};

class Student :public Person
{
protected:
	int _stuid;//ѧ����ѧ��
};

int main()

{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}