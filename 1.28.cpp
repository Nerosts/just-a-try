#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;

void test1()
{
	list<int> lt1;//�ղ�


	list<int> lt2(10, 2);//�Ž�ȥ10����

	string s("abc");
	list<int> lt3(s.begin(), s.end());//���õ�������ʼ��
}

void test2()
{
	string s("abc");
	list<int> lt(s.begin(), s.end());
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

void test3()
{
	string s("abc");
	list<int> lt(s.begin(), s.end());

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);//β������
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_back();//βɾһ��
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.push_front(1);//ͷ��һ��
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.pop_front();//ͷɾһ��
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.clear();//ȫɾ
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test4();
	return 0;
}