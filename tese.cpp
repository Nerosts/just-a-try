#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"BSTree.h"

void test1()
{
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.InsertR(e);
	}
	t.InOrder();
	t.Erase(8);
	t.InOrder();
	for (auto e : a)
	{
		t.Erase(e);
	}
	t.InOrder();
	cout << 1;
}

int main()
{
	test1();
	return 0;
}