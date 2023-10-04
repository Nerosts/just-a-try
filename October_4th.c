#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
//int main()
//{
//	char arr[] = "zyzyhaonb";
//	memset(arr, 'x', 4);
//	printf("%s",arr);
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 1,2,3,5 };
//	printf("%d", memcmp(arr1, arr2, 20));
//	return 0;
//}

//struct
//{
//	char a;
//	int b;
//}a1;
//
//struct
//{
//	char a;
//	int b;
//}*a2;
//
//int main()
//{
//	a2 = &a1;
//	return 0;
//}

struct Point
{
	int x;
	int y;
};

struct Node
{
	int a;
	struct Point p;
};

int main()
{
	struct Point p1 = { 1,2 };
	struct Point p2 = { .y = 2,.x = 1 };

	struct Node n1 = { 1,{1,2} };
	return 0;
}