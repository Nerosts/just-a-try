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
	Stack(size_t capacity = 3)
	{
		cout << "������Stack���캯��" << endl;

		_a = (int*)malloc(sizeof(int) * capacity);
		if (nullptr == _a)
		{
			perror("malloc����ռ�ʧ��!!!");
		}

		_capacity = capacity;
		_top = 0;
	}

	Stack(const Stack& stt)
	{
		cout << "�������" << endl;
		// ���
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
		cout << "������~Stack()" << endl;

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

//int main()
//{
//	Date d1(2024, 1, 4);
//	d1.Print();
//	Date d2(d1);
//	d2.Print();
//
//	Stack st1;
//	Stack st2(st1);
//
//	//MyQueue q1;
//	//MyQueue q2(q1);
//
//	return 0;
//}

// Date �� MyQueue Ĭ�����ɿ����Ϳ�����
// 1���������ͳ�Ա���ֵ����
// 2���Զ������ͳ�Ա���������Ա�Ŀ�������
// Stack��Ҫ�Լ�д�������죬��������
// ˳��������������ȵȵ��࣬����Ҫ���

class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int arr[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
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

	// ��ֵ���������
// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)//��ֵҲ�ǿ���
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
		while (_day > GetMonthDay(_year,_month))
		{
			
			_month++;

			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			_day -= GetMonthDay(_year, _month);//���¸�������˶�����
		}
		return *this;//���ر����ǿ��Եģ�this����������main������Ž���
	}

	// ����+����
	Date operator+(int day)
	{
		Date ret(*this);//��ʱ����
		ret += day;
		return ret;//���ܷ�������
	}

	// ����-=����
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

	// ����-����
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// ǰ��++
	Date& operator++()//ֻ++��ǰ��Ч�ʸ�
	{
		(*this) += 1;
		return *this;
	}

	// ����++
	Date operator++(int)//�涨������
	{
		Date tmp(*this);
		(*this) += 1;
		return tmp;//�Լ�����Ҫ�ӵģ����Ƿ���ԭ����
	}

	//?????????????????? ==���������


	bool operator==(Date d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator != (const Date& d)
	{
		return !((*this)==d);
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

	bool operator < (const Date& d)
	{
		return !((*this) >= d);
	}

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

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	d1.Print();
	//Date d2(2024, 1, 1);
	Date d2 = d1;//ʹ�����ظ�ֵ
	d2.Print();
	//++d2;
	//d2.Print();
	//bool ret1 = d1 > d2;//ʵ�����ǣ�d1.operator>(d2)  -->  d1.operator>(&d1,d2);
	//bool ret2 = d1 == d2;//ʵ�����ǣ�d1.operator==(d2)  -->  d1.operator==(&d1,d2);
	//cout << ret1 << endl;
	//cout << ret2 << endl;
	return 0;
}