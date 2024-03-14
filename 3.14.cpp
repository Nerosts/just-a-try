#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<set>
#include<map>
#include<vector>
//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//
//	pair() //构造函数
//	: first(T1()), second(T2())
//	{}
//
//	pair(const T1& a, const T2& b) //拷贝构造
//	: first(a), second(b)
//	{}
//};

void test_pair()
{
	pair<int, char> p1;//空参
	pair<int, char> p2(2, '2');

	pair<int, char> p3(p2);//拷贝构造

	auto p4 = make_pair(2, 'c');

	cout << p1.first << " " << p1.second << endl;;
	cout << p2.first << " " << p2.second << endl;
	cout << p3.first << " " << p3.second << endl;
}
void test_pair2()
{
	auto p4 = make_pair(2, 'c');//使用make_pair

	pair<int, char> p5 = { 3,'d' };//c++11后，使用{ }

	cout << p4.first << " " << p4.second << endl;
	cout << p5.first << " " << p5.second << endl;
}
void test_set1()
{
	set<int> s1;

	vector<int> v = { 1,2,3,4,5 };
	set<int> s2(v.begin(), v.end());//利用迭代区间

	set<int> s3 = s2;//拷贝构造
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;	
	for (auto e : s3)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	// 排序+去重
	set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(5);
	s.insert(1);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(5);//找到5就删除
	if (pos != s.end())
	{
		cout << "找到了" << endl;
		s.erase(pos);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	if (s.count(1))
	{
		cout << "1在" << endl;
	}
	else
	{
		cout << "1不在" << endl;
	}
}

void test_map()
{
	map<int, int> m1;//空参
	map<int,int> m2=
}

int main()
{
	test_set2();
	return 0;
}