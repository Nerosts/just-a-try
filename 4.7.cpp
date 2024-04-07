#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class T>
void test1(T&& x)
{
	cout << "T&& x" << endl;
}

template<class T>
void test2(T& x)
{
	cout << "T& x" << endl;
}

//class A
//{
//public:
//private:
//	int a=0;
//};
//A:: void print()
//{
//	cout << a << endl;
//}
//
//
//int main()
//{
//	int a = 10;
//	test1(a);
//	test1(1);
//	return 0;
//}

 ��������0-N������
 ��������������ȥ�ߣ�������������Ϊ����������ʱ��������
 ��������������ȥ�ߣ���Ϊ��ģ�壬����ʱ����
template <class ...Args>
void ShowList(Args... args)
{
	cout << sizeof...(args) << endl;
	for (size_t i = 0; i < sizeof...(args); i++)
	{
		cout << args[i] << " ";
	}
	cout << endl;
}

int main()
{
	ShowList();
	ShowList(1);
	ShowList(1, 'A');
	ShowList(1, 'A', std::string("sort"));

	return 0;
}