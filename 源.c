#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//void init(int arr[], int se)
//{
//	for (int i = 0; i < se; i++)
//	{
//		arr[i] = 0;
//	}
////}
//
//
//void print(int arr[], int se)
//{
//	for (int i = 0; i < se; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//
//void reverse(int arr[], int se)
//{
//	int* left = arr;
//	int* right = arr + se - 1;
//	//while (left <= right)
//	//{
//	//	int a = *left;
//	//	*left = *right;
//	//	*right = a;
//	//	left++;
//	//	right--;
//	//}
//	int a = *left;
//	*left = *right;
//	*right = '\0';
//	if (se > 2)
//	{
//		reverse(arr + 1, se - 2);
//	}
//	*right = a;
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int se = sizeof(arr) / sizeof(arr[1]);
//	//init(arr, se);
//	reverse(arr, se);
//	print(arr,se);
//	return 0;
//}
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 4,2,9,4,6 };
	int se = sizeof(arr1) / sizeof(arr1[1]);
	for (int i = 0; i < se; i++)
	{
		int t = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = t;
	}
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr2[i]);
	}
	
	return 0;
}