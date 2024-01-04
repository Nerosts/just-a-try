#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cassert>
using namespace std;

//class Date
//{
//public:
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	// 不能显示的写实参和形参
//	// void Print(Date* const this)
//	void Print()
//	{
//		//this = nullptr;
//		cout << this << endl;
//		// 但是可以在类里面显示的使用
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;//写出来也没事
//		cout << _year << "-" << _month << "-" << _day << endl;//正常是这样，不用写
//	}
//
//private:
//	int _year=1;     // 年
//	int _month=1;    // 月
//	int _day=1;      // 日
//};
//
//int main()
//{
//	Date d1;
//	//d1.Init(2023, 10, 19);
//	Date d2;
//
//	d1.Print(); // d1.Print(&d1);
//	d2.Print();
//
//	return 0;
//}

//class A
//{
//public:
//	void print()
//	{
//		cout << "print()" << endl;
//		cout << _a;//多了这个，对a指向的空间访问
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* a = nullptr;//现在是空指针
//	a->print();
//	return 0;
//}

//class Date
//{
//public:
//	Date() //无参构造函数
//	{   
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)//有参构造函数  ，二者构成重载
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1;//调用无参构造函数
//	d1.Print(); 
//
//	Date d2(2024, 1, 3);//调用带参构造函数
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year=1, int month=1, int day=1)//有参构造函数  ，二者构成重载
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1;//调用带参构造函数，全缺省
//	d1.Print();
//
//	Date d2(2024, 1, 3);//调用带参构造函数
//	d2.Print();
//
//	Date d3(2024);//传部分也行
//	d3.Print();
//	return 0;
//}

//class Date
//{
//public:
//	//此时没有进行显示构造函数定义，会使用系统默认生成的无参构造函数
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//};
//
//int main()
//{
//	Date d1;//调用默认构造函数
//	d1.Print();
//	return 0;
//}

//class Stack
//{
//public:
//	//Stack(int capacity = 3)
//	//{
//	//	_a = (int*)malloc(sizeof(int) * capacity);
//	//	assert(_a);
//	//	_capacity = capacity;
//	//	_top = -1;
//	//}
//
//private:
//	int* _a=nullptr;
//	int _top=-1;
//	int _capacity=1;//这三个是内置类型
//};
//
//int main()
//{
//	Stack s1;
//
//	return 0;
//}


class Time
{
public:
	~Time()
	{
		cout << "调用了time的析构函数" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	// 基本类型(内置类型)
	int _year = 1;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _time;
};

int main()
{
	Date d1;
	return 0;
}

//class Date
//{
//public:
//	//此时没有进行显示构造函数定义，会使用系统默认生成的无参构造函数
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	~Date()
//	{
//		cout << "调用了析构函数";
//	}
//
//private:
//	int _year=1;     // 年
//	int _month=1;    // 月
//	int _day=1;      // 日
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}
