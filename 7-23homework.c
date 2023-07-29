#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//递归和非递归分别实现求第n个斐波那契数
//例如：
//输：5  输出：5
//输入：10， 输出：55
//输入：2， 输出：1
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//
//	return 0;
//}

//递归和非递归分别实现strlen
//int main()
//{
//	char arr[] = "hellow world";
//	int length = 0;
//	char* a = arr;
//	while (*a != '\0')
//	{
//		length++;
//		a++;
//	}
//	printf("%d", length);
//	return 0;
//}
int my_strlen(char* a)
{
	if (*a != '\0')
	{
		return 1 + my_strlen(++a);
	}
	else
	{
		return 0;
	}
}
//int main()
//{
//	char arr[] = "hellow world";
//	printf("%d", my_strlen(arr));
//	return 0;
//}

//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int x = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		x *= i;
//	}
//	printf("%d", x);
//	return 0;
//}
//int get_Factorial(int x)
//{
//	if (x > 1)
//	{
//		return x * get_Factorial(x-1);
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	int n = 3;
//	printf("%d", get_Factorial(n));
//	return 0;
//}
//int Fib(int a)
//{
//	if (a <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(a - 1) + Fib(a - 2);
//	}
//}
//int Fib(int a)
//{
//	int i = 1;
//	int j = 1;
//	int x = 0;
//	while (a >= 3)
//	{
//		x = i + j;
//		i = j;
//		j = x;
//		a--;
//	}
//	return x;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", Fib(n));
//	return 0;
//}
//编写一个函数实现n的k次方，使用递归实现。
//int Fun(int n, int k)
//{
//	if (k > 1)
//	{
//		return n * Fun(n, k - 1);
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	int n = 4;
//	int k = 0;
//	scanf("%d", &k);
//	printf("%d", Fun(n, k));
//	return 0;
//}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//
////输入：1729，输出：19
//int DigitSun(int a)
//{
//	if (a > 9)
//	{
//		return a % 10 + DigitSun(a / 10);
//	}
//	else
//	{
//		return a % 10;
//	}
//}
//
//
//
//int main()
//{
//	int a = 1729;
//	printf("%d", DigitSun(a));
//	return 0;
//}

//编写一个函数 reverse_string(char* string)（递归实现）
//
//实现：将参数字符串中的字符反向排列，不是逆序打印。
//
//要求：不能使用C函数库中的字符串操作函数。
//
//比如 :
//
//char arr[] = "abcdef";
//逆序之后数组的内容变成：fedcba
void reverse_string(char* string)
{
	int right = my_strlen(string) - 1;
	char temp = *string;
	*string = *(string + right);
	*(string + right) = '\0';
	if (right > 1)
	{
		reverse_string(string + 1);
	}
	*(string + right) = temp;
}

int main()
{
	char arr[] = "abcdef";
	reverse_string(arr);
	printf("%s", arr);
	return 0;
}