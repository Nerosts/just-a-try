#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	int* pa = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(pa++));
//	}
//	return 0;
//}
//int my_strlen(char* pa)
//{
//	char* start = pa;
//	while (*pa)
//	{
//		pa++;
//	}
//	return pa - start;
//}
//
//int main()
//{
//	char arr[] = "hello";
//	printf("%d", my_strlen(arr));
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2 };
//	int* pa = arr;
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;//一级指针
//	int** ppa = &pa;//二级指针
//	printf("%d\n", a);
//	**ppa = 0;//通过两次解引用来改变值
//	printf("%d\n", a);
//	return 0;
//}

int main()
{
	int arr1[] = { 1,2,4,6 };
	int arr2[] = { 7,2,4,4 };
	int arr3[] = { 1,2,9,6 };

	int* p[] = { arr1,arr2,arr3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
