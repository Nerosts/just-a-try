#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

void test1()
{
	vector<int> v1;//空参构造

	vector<int> v2(5, 1);//构造并初始化5个1

	vector<int> v3(v2);//拷贝构造

	string s1("abc");
	vector<int> v4(s1.begin(), s1.end());//使用迭代器进行初始化构造

	
}

void test2()
{
	string s1("abc");
	vector<char> v(s1.begin(), s1.end());//使用迭代器进行初始化构造

	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

void test3()
{
	string s1("abc");
	vector<int> v(s1.begin(), s1.end());//使用迭代器进行初始化构造

	for (auto e : v)
	{
		cout << e << " ";
	}
}

void test4()
{
	string s1("abc");
	vector<char> v(s1.begin(), s1.end());//使用迭代器进行初始化构造

	vector<char>::iterator it = v.begin();//正向遍历
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<char>::reverse_iterator rit = v.rbegin();//正向遍历
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;//是++不是--
	}
	//反向迭代器的移动方向是与正向迭代器相反的
	//即 ++ 操作符会使迭代器向前移动，而 -- 操作符会使迭代器向后移动
}

void test5()
{
	vector<int> v(10, 1);//10个1
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
	vector<int> v(10, 1);//10个1
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
	vector<int> v(10, 1);//10个1
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

	vector<int>::iterator it = find(v.begin(), v.end(), 3);//找到3的位置
	v.insert(it, 0);//插入
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin(),v.end());//全删了
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
	cout << "还没交换" << endl;
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	v1.swap(v2);//二者交换
	cout << "交换后" << endl;
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