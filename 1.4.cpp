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
//	// ������ʾ��дʵ�κ��β�
//	// void Print(Date* const this)
//	void Print()
//	{
//		//this = nullptr;
//		cout << this << endl;
//		// ���ǿ�������������ʾ��ʹ��
//		cout << this->_year << "-" << this->_month << "-" << this->_day << endl;//д����Ҳû��
//		cout << _year << "-" << _month << "-" << _day << endl;//����������������д
//	}
//
//private:
//	int _year=1;     // ��
//	int _month=1;    // ��
//	int _day=1;      // ��
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
//		cout << _a;//�����������aָ��Ŀռ����
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* a = nullptr;//�����ǿ�ָ��
//	a->print();
//	return 0;
//}

//class Date
//{
//public:
//	Date() //�޲ι��캯��
//	{   
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)//�вι��캯��  �����߹�������
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
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//};
//
//int main()
//{
//	Date d1;//�����޲ι��캯��
//	d1.Print(); 
//
//	Date d2(2024, 1, 3);//���ô��ι��캯��
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//
//	Date(int year=1, int month=1, int day=1)//�вι��캯��  �����߹�������
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
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//};
//
//int main()
//{
//	Date d1;//���ô��ι��캯����ȫȱʡ
//	d1.Print();
//
//	Date d2(2024, 1, 3);//���ô��ι��캯��
//	d2.Print();
//
//	Date d3(2024);//������Ҳ��
//	d3.Print();
//	return 0;
//}

//class Date
//{
//public:
//	//��ʱû�н�����ʾ���캯�����壬��ʹ��ϵͳĬ�����ɵ��޲ι��캯��
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//};
//
//int main()
//{
//	Date d1;//����Ĭ�Ϲ��캯��
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
//	int _capacity=1;//����������������
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
		cout << "������time����������" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
private:
	// ��������(��������)
	int _year = 1;
	int _month = 1;
	int _day = 1;
	// �Զ�������
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
//	//��ʱû�н�����ʾ���캯�����壬��ʹ��ϵͳĬ�����ɵ��޲ι��캯��
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	~Date()
//	{
//		cout << "��������������";
//	}
//
//private:
//	int _year=1;     // ��
//	int _month=1;    // ��
//	int _day=1;      // ��
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//	return 0;
//}
