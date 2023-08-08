#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//题目：
//
//输入一个整数数组，实现一个函数，
//
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//
//所有偶数位于数组的后半部分。
//void change(int* arr)
//{
//	int* destination = arr + 1;
//	int* odd = arr + 2;
//	while (destination < arr + 3)
//	{
//		int t = *odd;
//		*odd = *destination;
//		*destination = t;
//		odd=odd + 2;
//		destination=destination + 1;
//	}		
//}
//
//
//int main()
//{
//	int arr[6] = { 1,2,3,4,5,6 };
//	
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	change(arr);
//	printf("\n");
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//模拟实现strcpy
//char* my_strcpy(char* des, const char* cors)
//{
//	assert(*des);
//	assert(*cors);
//	while (*des++ = *cors++)
//	{
//		;
//	}
//	
//	return des;
//}
//
//
//int main()
//{
//	char arr1[] = "***********";
//	char arr2 []= "abcdef";
//	printf("%s\n", arr1);
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//}

//模拟实现strlen;
//size_t my_strlen(const char* a)
//{
//	assert(a);
//	size_t count = 0;
//	while (*a)
//	{
//		count++;
//		a++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t se =my_strlen(arr);
//	printf("%zd", se);
//	return 0;
//}

//int main()
//{
//	//需要注意的是：数组下标是从0开始的
//	char arr1 []= "hello";
//	char arr2[] = { 'h','e','l','l','o' };
//	//对应的下标：   0   1   2   3   4
//
//	printf("%c", arr2[0]);//来输出一个h看看吧
//
//	return 0;
//}
//int main()
//{
//	int arr1[3][4] = { 1,2,3,4 };//这种初始化在一行满了后就换到下一行
//	int arr2[3][4] = { {1,2},{4,5} };//这种初始化已经规定一行的元素，不够的来填0
//	int arr3[][4] = { {2,3},{4,5} };//需要注意的是：二维数组如果有初始化，行可以省略，列不能省略
//
//	return 0;
//}
//int main()
//{
//	int arr[2][3] = { {1,4},{2,3} };
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][4];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d]的地址是： %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}

int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i <= 10; i++)
	{
		printf("arr[%d]=%d\n",i, arr[i]);//当i等于10的时候，越界访问了
	}
	return 0;
}
