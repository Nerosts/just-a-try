#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int line = 0;
//	scanf("%d", &line);
//	//开始输出上半部分
//	for (int i = 1; i <= line; i++)
//	{
//		//先输出空格
//		for (int j = 1; j <= line - i; j++)
//		{
//			printf(" ");
//		}
//
//		for (int j = 1; j <= 2 * i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	//开始输出下半部分
//	for (int i = 1; i <= line - 1; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf(" ");
//		}
//
//		for (int j = 1; j <= (line - i) * 2 - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int total = 0;
//	scanf("%d", &n);//自己输入钱数
//	total = n;
//	int bottle = n;//一开始剩的瓶子数是钱数
//	while (bottle >= 2)
//	{
//		total = total + bottle / 2;
//		bottle = bottle / 2 + bottle % 2;
//	}
//	printf("%d", total);
//	return 0;
//}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
		int sz = sizeof(arr) / sizeof(arr[0]);
	
		int left = 0;
		int right = sz - 1;
	
		while (left<right)
		{
			//从前往后找一个偶数
			while ( arr[left] % 2 == 1)
			{
				left++;
			}
			//从后往前找一个奇数
			while (arr[right] % 2 == 0)
			{
				right--;
			}
			//交换
	
				int tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			
		}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}