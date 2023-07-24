#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//void print_table(int a)
//{
//	for (int i = 1; i <= a; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//
//
//
//int main()
//{
//	int row = 0;
//	scanf("%d", &row);
//	print_table(row);
//	return 0;
//}
//

//实现一个函数来交换两个整数的内容
//void exchange(int* a, int* b)
//{
//	int t = 0;
//	t = *a;
//	*a = *b;
//	*b = t;
//	
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d %d", a, b);
//	exchange(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

//实现函数判断year是不是润年。
//int judge_leapyear(int a)
//{
//	if ((a % 4 == 0 && a % 100 != 0) || (a % 400== 0))
//	{
//		return 1;
//	}
//	return 0;
//}
//
//
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	if (judge_leapyear(year)) {
//		printf("%d是闰年",year);
//	}
//	else {
//		printf("%d不是闰年",year);
//	}
//}

//实现一个函数is_prime，判断一个数是不是素数。
//
//利用上面实现的is_prime函数，打印100到200之间的素数。
//bool is_prime(int a)
//{
//	for (int i = 2; i <=sqrt(a) ; i++)
//	{
//		if (a % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	for (int i = 100; i <= 200; i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d     是素数\n", i);
//		}
//		else
//		{
//			printf("%d不是素数\n", i);
//
//		}
//		
//	}
//	return 0;
//}

//递归方式实现打印一个整数的每一位
void print(int a)
{
	if (a > 9)
	{
		print(a / 10);
	}
	printf("%d", a % 10);
}

int main()
{
	int x = 1234;
	print(x);
	return 0;
}