#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Stack
{
private:
	int* a;
	int top;
	int capacity;
public:
	void Init(size_t capacity);//��������

	//............
};
void Stack::Init(size_t capacity)//���ⶨ��   ע�����  ��������
{
	a = nullptr;
	top = -1;
	capacity = 0;
}

//class Date
//{
//public:
//	int _year;
//	int _mouth;
//	int _day;
//public:
//	void Init(int year, int mouth, int day);
//};
//
//void Date::Init(int year, int mouth, int day)
//{
//	_year = year;
//}
//
//class A
//{
//private:
//	char a;
//	int b;
//public:
//	void print();
//};

//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};

//struct S2
//{
//	struct S1
//	{
//		char c1;
//		int i;
//		char c2;
//	};
//	int a;
//};
//
//int main()
//{
//	cout << sizeof(S2);
//	return 0;
//}

 //C++����c����struct�������÷�
 //structͬʱ����������
 //1�������������ͣ�Stack�������ͣ�����Ҫ��struct
 //2�������涨�庯��


//class Date
//{
//public:
//	void InitDate(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void PrintDate(Date* this)
//	{
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1;
//	Date d2;
//
//	d1.InitDate(2024, 1, 2);
//	d2.InitDate(2023, 1, 2);
//
//	d1.PrintDate(&d1);
//	d2.PrintDate(&d2);
//
//	return 0;
//}

void Function2(int a = 1, int b = 2, int c = 3)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
int main()
{
	Function2(;
	return 0;
}