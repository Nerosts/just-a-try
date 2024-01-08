#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Stack
//{
//public:
//	Stack(size_t capacity)
//	{
//		cout << "调用了Stack构造函数" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//Stack(const Stack& stt)
//	//{
//	//	cout << "拷贝完成" << endl;
//	//	// 深拷贝
//	//	_a = (int*)malloc(sizeof(int) * stt._capacity);
//	//	if (_a == nullptr)
//	//	{
//	//		perror("malloc fail");
//	//		exit(-1);
//	//	}
//	//	memcpy(_a, stt._a, sizeof(int) * stt._top);
//	//	_top = stt._top;
//	//	_capacity = stt._capacity;
//	//}
//
//	~Stack()
//	{
//		cout << "调用了~Stack()" << endl;
//
//		free(_a);
//		_capacity = _top = 0;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//class MyQueue
//{
//public:
//	MyQueue()
//		:_pushst(1)
//		, _popst(2)//初始化列表
//	{
//
//	}
//	//MyQueue()
//	//{
//	//	_pushst = 1;
//	//	_popst = 2;
//	//}
//private:
//	Stack _pushst;//有可能不提供默认构造函数：只有自己显式的非全缺省参数的
//	Stack _popst;
//	int _size = 0;
//};
//
//class A
//{
//public:
//	A() { count++; }
//	A(A& a) { count++; }
//private:
//	static int count;
//	int _a;
//};
//
//int A::count = 0;
//
//int main()
//{
//	Date d1;//调用构造函数
//	Date d2 = d1;//这是调用拷贝构造；
//	//一个已经存在的对象，拷贝初始化另一个要创建的对象时拷贝构造
//
//	Date d3;
//	d3 = d1;//这是赋值重载函数：两个对象都存在，进行赋值拷贝
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2024, int month = 1, int day = 1)//使用全缺省，也是默认构造函数
//	{
//		//函数体内初始化，在函数体内进行赋值
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(int year = 2024, int month = 1, int day = 1)//使用全缺省，也是默认构造函数
//		:_year(year)
//		,_month(month)
//		,_day(day)  //这三个可以在这，也可以在函数体内
//		,_ref(year)
//		,_n(1)  //这两个必须在这里
//	{
//
//	}
//	两个地方可以混着用，这样也行
//	Date(int year = 2024, int month = 1, int day = 1)
//		: _ref(year)
//		, _n(1)  //这两个必须在这里
//	{
//		_year = year;
//		_month = month;
//		_day = day;//这三个可以在这，也可以在初始化列表内
//	}
//private:
//	int _year=1;//这些都是声明，还没有空间
//	int _month;
//	int _day;
//
//	int& _ref=_month;//引用，必须在定义的时候初始化
//	const int _n=2;//常量，必须在定义的时候初始化
//};

class Date
{
public:
	//两个地方可以混着用，这样也行
	Date(int year = 2024, int month = 1, int day = 1)
		: _ref(year)
		, _n(1)  //这两个必须在这里
	{
		_year = year;
		_month = month;
		_day = day;//这三个可以在这，也可以在初始化列表内
	}
private:
	int _year = 1;//这些都是声明，还没有空间
	int _month ;
	int _day ;

	int& _ref;//引用，必须在定义的时候初始化
	const int _n = 2;//常量，必须在定义的时候初始化
};

class Stack
{
public:
	Stack(int capacity=3)
	{
		cout << "调用了Stack的默认构造函数";
		//.......
	}
	//没有默认构造函数了
private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue
{
public:
	MyQueue()//有没有效果一样，没写就按照默认构造函数那老一套
	{ }  //写了初始化列表一定会走，但没有显示的写那也是老一套
private:
	Stack _s1;
	Stack _s2;//这俩可调用Stack类的默认构造
	int _size = -1;//给了缺省值
	
};

int main()
{
	//实例化对象
	//Date d1;//此时才定义，但是对象整体定义； 那每个成员在哪里定义呢？——就在初始化列表
	MyQueue q1;
	return 0;
}