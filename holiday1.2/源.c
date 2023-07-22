#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//写一个代码打印1 - 100之间所有3的倍数的数字
//int main()
//{
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0) {
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}
//写代码将三个整数数按从大到小输出。
//
//例如：
//
//输入：2 3 1
//
////输出：3 2 1
//int main()
//{
//	int a[10];
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = i+1; j < 10; j++)
//		{
//			if (a[i] < a[j])
//			{
//				int exchange = a[i];
//				a[i] = a[j];
//				a[j] = exchange;
//			}
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d", a[i]);
//	}
//	return 0;
//}

//写一个代码：打印100~200之间的素数
//int main()
//{
//
//	int flag = 1;
//	for (int i = 100; i <= 200; i++)
//	{
//		flag = 1;
//		for (int j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0) {
//				flag = 0;
//			}
//		}
//		if (flag)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//	return 0;
//
//}

//打印1000年到2000年之间的闰年
//int main()
//{
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}

//给定两个数，求这两个数的最大公约数
//
//例如：
//
//输入：20 40
//
//输出：20
//int main()
//{
//	int a, b;
//	int n = 1;
//	scanf("%d%d", &a, &b);
//	n = a % b;
//	while (n) 
//	{
//		
//		a = b;
//		b = n;
//		n = a % b;
//	}
//	printf("%d",b);
//
//	return 0;
//}

//在屏幕上输出9 * 9乘法口诀表
//int main()
//{
//	for (int j = 1; j <= 9; j++)
//	{
//		for (int i = 1; i <= j; i++) {
//			printf("%d * %d =%d  ", j, i, j * i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值，打印出结果
//int main()
//{
//	double sum = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum = sum + 1.0 / (i * 1.0);
//	}
//	printf("%lf", sum);
//	return 0;
//}
int main()
{
	int sum = 0;
	int jie = 1;
	for (int n = 1; n <= 3; n++)
	{
		jie = 1;
		for (int i = 1; i <= n; i++)
		{
			jie *= i;
		}
		sum += jie;
	}
	printf("%d", sum);
	return 0;

}