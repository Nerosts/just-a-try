#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;//空参构造

	vector<int> v2(5, 1);//构造并初始化5个1

	vector<int> v3(v2);//拷贝构造

	string s1("abc");
	vector<int> v4(s1.begin(), s1.end());//使用迭代器进行初始化构造

	return 0;
}