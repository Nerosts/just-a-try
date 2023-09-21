#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char a = 'z';
//	char* pa = &a;
//	return 0;
//}

//int main()
//{
//	char* arr = "hello";
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "hello";
//	const char* str3 = "hello";
//	const char* str4 = "hello";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//int main()
//{
//	int arr1[4] = { 1,2,4,5 };
//	int arr2[4] = { 2,2,5,5 };
//	int arr3[4] = { 1,1,4,4 };
//
//	int* pa[3] = { &arr1,&arr2,&arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", pa[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "abc";
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//
//	return 0;
//}

//void print_arr(int(*arr)[5], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	//数组名arr，表示首元素的地址
//	//但是二维数组的首元素是二维数组的第一行
//	//所以这里传递的arr，其实相当于第一行的地址，是一维数组(有五个元素)的地址
//	//可以数组指针来接收
//	print_arr(arr, 3, 5);
//	return 0;
//}

//void test(int arr[])//可以    数组传参，形参是可以写成数组形式的
//{}
//void test(int arr[10])//可以
//{}
//void test(int* arr)//可以     数组传参的本质是传递了数组首元素的地址，形参也可以是指针
//{}
//void test2(int* arr[20])//可以 
//{}
//void test2(int** arr)//可以  传过来的是int* 的地址，就用int**来接收
//{}
//int main()
//{
//	int arr[10] = { 0 };
//
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}

////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//
//void test(int arr[3][5])//可以
//{}
//void test(int arr[][])//不可以：只能省略行，不能省略列
//{}
//void test(int arr[][5])//可以
//{}
//									
//void test(int* arr)//不可以
//{}
//void test(int* arr[5])//不可以
//{}
//void test(int(*arr)[5])//可以
//{}
//void test(int** arr)//不可以
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}

//void print(int* p, int sz)  //形参的部分写成一级指针就行了
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* pa = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	print(pa, sz);
//	return 0;
//}

void test(int** ptr)
{
	printf("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);//传过来的是二级指针
	test(&p);
	return 0;
}