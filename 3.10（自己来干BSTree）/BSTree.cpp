#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include"BSTree.h"

int main()
{
	key::BSTree<int> t;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();

	t.Erase(8);
	t.InOrder();

	t.Erase(14);
	t.InOrder();

	t.Erase(4);
	t.InOrder();

	t.Erase(6);
	t.InOrder();
	return 0;
}