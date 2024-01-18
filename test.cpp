#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"string.h"

namespace MyString
{
	void test6()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;
		int pos = s1.find('b');
		string s2 = s1.substr(pos, 2);
		cout << s2 << endl;
	}
}

int main()
{
	MyString::test6();
	return 0;
}
