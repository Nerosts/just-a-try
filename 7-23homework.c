#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//���磺
//�䣺5  �����5
//���룺10�� �����55
//���룺2�� �����1
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//
//	return 0;
//}

//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
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

//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
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
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
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

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//
////���룺1729�������19
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

//��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//
//ʵ�֣��������ַ����е��ַ��������У����������ӡ��
//
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//
//���� :
//
//char arr[] = "abcdef";
//����֮����������ݱ�ɣ�fedcba
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