#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubbleSort(int arr[], int se)
{
	for (int i = 0; i < se - 1; i++)//n个元素排序n-1个后就OK了，最后一个自动排好了
	{
		for (int j = 0; j < se - 1 - i; j++)//每排好一个后面就少比一次，所以减去i
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int arr[] = { 5,2,9,1,3 };
	int se = sizeof(arr) / sizeof(arr[0]);//常用的方法来求数组长度；
	//开始打印排序前数组
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//调用函数进行排序
	bubbleSort(arr, se);
	//打印排序后的
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}