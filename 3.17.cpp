#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>

using namespace std;

void testmap1()
{
	map<string, string> m1;//空的
	map<string, string> m2(m1);//拷贝构造
}

void testmap2()
{
	map<string, string> m1;//空的
	
	m1.insert(pair<string, string>("sort", "排序"));//匿名对象
	m1.insert(make_pair("apple", "苹果"));//使用make_pair函数
	m1.insert({ "apple", "苹果" });// C++11 多参数隐式类型转换(构造函数支持)
}
void testmap3()
{
	map<string, string> m1;//空的

	m1.insert(pair<string, string>("sort", "排序"));//匿名对象
	m1.insert(make_pair("apple", "苹果"));//使用make_pair函数
	m1.insert({ "left", "左边" });// C++11 多参数隐式类型转换(构造函数支持)
	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;

	m1["right"];//这是插入一个right（key）
	m1["apple"] = "青苹果";//这里是进行修改

	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;
}

int main()
{
	testmap3();
	return 0;
}