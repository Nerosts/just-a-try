#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void test1()
{
	vector<int> v1;//�ղι���

	vector<int> v2(5, 1);//���첢��ʼ��5��1

	vector<int> v3(v2);//��������

	string s1("abc");
	vector<int> v4(s1.begin(), s1.end());//ʹ�õ��������г�ʼ������

	
}

void test2()
{
	string s1("abc");
	vector<char> v(s1.begin(), s1.end());//ʹ�õ��������г�ʼ������

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

void test3()
{
	string s1("abc");
	vector<int> v(s1.begin(), s1.end());//ʹ�õ��������г�ʼ������

	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test4()
{
	string s1("abc");
	vector<char> v(s1.begin(), s1.end());//ʹ�õ��������г�ʼ������

	vector<char>::iterator it = v.begin();//�������
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<char>::reverse_iterator rit = v.rbegin();//�������
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;//��++����--
	}
	//������������ƶ�������������������෴��
	//�� ++ ��������ʹ��������ǰ�ƶ����� -- ��������ʹ����������ƶ�
}

void test5()
{
	vector<int> v(10, 1);//10��1
	cout << v.capacity() << endl;
	v.reserve(20);
	cout << v.capacity() << endl;
	v.reserve(15);
	cout << v.capacity() << endl;
	v.reserve(5);
	cout << v.capacity() << endl;
}

void test6()
{
	vector<int> v(10, 1);//10��1
	cout << "capacity:" << v.capacity() << "size:" << v.size() << endl;
	v.resize(20);
	cout << "capacity:" << v.capacity() << "size:" << v.size() << endl;
	v.resize(15);
	cout << "capacity:" << v.capacity() << "size:" << v.size() << endl;
	v.resize(5);
	cout << "capacity:" << v.capacity() << "size:" << v.size() << endl;
}

void test7()
{
	vector<int> v(10, 1);//10��1
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.push_back(10);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.pop_back();
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test8()
{
	vector<int> v;
	for (int i = 1; i < 6; i++)
	{
		v.push_back(i);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int>::iterator it = find(v.begin(), v.end(), 3);//�ҵ�3��λ��
	v.insert(it, 0);//����
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin(),v.end());//ȫɾ��
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test9()
{
	vector<int> v1;
	for (int i = 1; i < 6; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2(10, 1);
	cout << "��û����" << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.swap(v2);//���߽���
	cout << "������" << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test9();
}