#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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

//ʵ��һ��������������������������
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

//ʵ�ֺ����ж�year�ǲ������ꡣ
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
//		printf("%d������",year);
//	}
//	else {
//		printf("%d��������",year);
//	}
//}

//ʵ��һ������is_prime���ж�һ�����ǲ���������
//
//��������ʵ�ֵ�is_prime��������ӡ100��200֮���������
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
//			printf("%d     ������\n", i);
//		}
//		else
//		{
//			printf("%d��������\n", i);
//
//		}
//		
//	}
//	return 0;
//}

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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