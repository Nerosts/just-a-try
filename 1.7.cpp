#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
using namespace std;

//class Date
//{
//public:
//	Date(int year = 2014, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class Stack
{
public:
	//Stack(size_t capacity = 3)
	//{
	//	cout << "调用了Stack构造函数" << endl;

	//	_a = (int*)malloc(sizeof(int) * capacity);
	//	if (nullptr == _a)
	//	{
	//		perror("malloc申请空间失败!!!");
	//	}

	//	_capacity = capacity;
	//	_top = 0;
	//}

	Stack(const Stack& stt)
	{
		cout << "拷贝完成" << endl;
		// 深拷贝
		_a = (int*)malloc(sizeof(int) * stt._capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
		memcpy(_a, stt._a, sizeof(int) * stt._top);
		_top = stt._top;
		_capacity = stt._capacity;
	}

	~Stack()
	{
		cout << "调用了~Stack()" << endl;

		free(_a);
		_capacity = _top = 0;
		_a = nullptr;
	}

private:
	int* _a;
	int _capacity;
	int _top;
};

class MyQueue
{
	Stack _pushst;
	Stack _popst;
	int _size = 0;
};

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;//来进行多次输出
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;

	return in;
}

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return arr[month];
	}

	Date(int year = 2024, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	~Date()
	{
		;
	}

	// 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)//赋值也是拷贝
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}



	Date& operator+=(int day)
	{
		if (day < 0)
		{
			return (*this) -= (-day);
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{

			_month++;

			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			_day -= GetMonthDay(_year, _month);//从下个月里借了多少天
		}
		return *this;//返回别名是可以的，this的作用域在main结束后才结束
	}

	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this);//临时变量
		ret += day;
		return ret;//不能返回引用
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 1)
		{
			_day += GetMonthDay(_year, _month);
			_month--;

			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
		}
		return *this;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// 前置++
	Date& operator++()//只++，前置效率高
	{
		(*this) += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)//规定这样的
	{
		Date tmp(*this);
		(*this) += 1;
		return tmp;//自己还是要加的，但是返回原本的
	}

	//?????????????????? ==运算符重载


	bool operator==(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator != (const Date& d)
	{
		return !((*this) == d);
	}

	bool operator>(Date d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator >= (const Date& d)
	{
		return (*this) > d || (*this) == d;
	}

	bool operator < (const Date& d);

	bool operator <= (const Date& d)
	{
		return !((*this) >= d);
	}

	int operator-(Date d)
	{
		int count = 0;
		int flag = 1;
		Date max = *this;
		Date min = d;
		if ((*this) < d)
		{
			int flag = -1;
			max = d;
			min = *this;
		}
		while (min != max)
		{
			count++;
			++min;
		}
		return flag * count;
	}

	void Print() const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	void Print(const Date* this)
	{
		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
	}

	friend ostream& operator<<(ostream& out,const Date& d);
	friend istream& operator>>(istream& in,Date& d);

	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const//参数是const Date* this，因为保证*this不变（内容不变，指向可以变）
	{
		return this;//返回const Date* 类型
	}

private:
	int _year;
	int _month;
	int _day;
};

bool Date::operator < (const Date& d)
{
	return !((*this) >= d);
}

int main()
{
	const Date d1(2024, 1, 1);
	Date d2(2024,15);
	d2 < d1;
	d1 < d2;
	return 0;
}

//int main()
//{
//	Date d1;
//	d1.Print();
//	//Date d2(2024, 1, 1);
//	Date d2 = d1;//使用重载赋值
//	d2.Print();
//	//++d2;
//	//d2.Print();
//	//bool ret1 = d1 > d2;//实际上是：d1.operator>(d2)  -->  d1.operator>(&d1,d2);
//	//bool ret2 = d1 == d2;//实际上是：d1.operator==(d2)  -->  d1.operator==(&d1,d2);
//	//cout << ret1 << endl;
//	//cout << ret2 << endl;
//	return 0;
//}