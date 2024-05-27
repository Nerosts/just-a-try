#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

int main()
{
	int arr[10] = { 1,3,4 };
	for (int i = 10; i > 1; i++)
	{
		arr[i] = arr[i - 1];
	}
	return 0;
}

enum A
{
	red,
	black
};


enum class B
{
	red,
	black
};