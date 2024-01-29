#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"Stack.h"
#include<vector>
#include<deque>
using namespace std;

int main()
{
	MyStack::stack<int,vector<int>> s1;
	s1.push(1);
	s1.push(2);
	while (!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
	return 0;
}