#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Stack
//{
//public:
//	Stack(size_t capacity)
//	{
//		cout << "������Stack���캯��" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc����ռ�ʧ��!!!");
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	//Stack(const Stack& stt)
//	//{
//	//	cout << "�������" << endl;
//	//	// ���
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
//		cout << "������~Stack()" << endl;
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
//		, _popst(2)//��ʼ���б�
//	{
//
//	}
//	//MyQueue()
//	//{
//	//	_pushst = 1;
//	//	_popst = 2;
//	//}
//private:
//	Stack _pushst;//�п��ܲ��ṩĬ�Ϲ��캯����ֻ���Լ���ʽ�ķ�ȫȱʡ������
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
//	Date d1;//���ù��캯��
//	Date d2 = d1;//���ǵ��ÿ������죻
//	//һ���Ѿ����ڵĶ��󣬿�����ʼ����һ��Ҫ�����Ķ���ʱ��������
//
//	Date d3;
//	d3 = d1;//���Ǹ�ֵ���غ������������󶼴��ڣ����и�ֵ����
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 2024, int month = 1, int day = 1)//ʹ��ȫȱʡ��Ҳ��Ĭ�Ϲ��캯��
//	{
//		//�������ڳ�ʼ�����ں������ڽ��и�ֵ
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date(int year = 2024, int month = 1, int day = 1)//ʹ��ȫȱʡ��Ҳ��Ĭ�Ϲ��캯��
//		:_year(year)
//		,_month(month)
//		,_day(day)  //�������������⣬Ҳ�����ں�������
//		,_ref(year)
//		,_n(1)  //����������������
//	{
//
//	}
//	�����ط����Ի����ã�����Ҳ��
//	Date(int year = 2024, int month = 1, int day = 1)
//		: _ref(year)
//		, _n(1)  //����������������
//	{
//		_year = year;
//		_month = month;
//		_day = day;//�������������⣬Ҳ�����ڳ�ʼ���б���
//	}
//private:
//	int _year=1;//��Щ������������û�пռ�
//	int _month;
//	int _day;
//
//	int& _ref=_month;//���ã������ڶ����ʱ���ʼ��
//	const int _n=2;//�����������ڶ����ʱ���ʼ��
//};

class Date
{
public:
	//�����ط����Ի����ã�����Ҳ��
	Date(int year = 2024, int month = 1, int day = 1)
		: _ref(year)
		, _n(1)  //����������������
	{
		_year = year;
		_month = month;
		_day = day;//�������������⣬Ҳ�����ڳ�ʼ���б���
	}
private:
	int _year = 1;//��Щ������������û�пռ�
	int _month ;
	int _day ;

	int& _ref;//���ã������ڶ����ʱ���ʼ��
	const int _n = 2;//�����������ڶ����ʱ���ʼ��
};

class Stack
{
public:
	Stack(int capacity=3)
	{
		cout << "������Stack��Ĭ�Ϲ��캯��";
		//.......
	}
	//û��Ĭ�Ϲ��캯����
private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue
{
public:
	MyQueue()//��û��Ч��һ����ûд�Ͱ���Ĭ�Ϲ��캯������һ��
	{ }  //д�˳�ʼ���б�һ�����ߣ���û����ʾ��д��Ҳ����һ��
private:
	Stack _s1;
	Stack _s2;//�����ɵ���Stack���Ĭ�Ϲ���
	int _size = -1;//����ȱʡֵ
	
};

int main()
{
	//ʵ��������
	//Date d1;//��ʱ�Ŷ��壬���Ƕ������嶨�壻 ��ÿ����Ա�����ﶨ���أ��������ڳ�ʼ���б�
	MyQueue q1;
	return 0;
}