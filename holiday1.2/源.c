#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//дһ�������ӡ1 - 100֮������3�ı���������
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
//д���뽫�������������Ӵ�С�����
//
//���磺
//
//���룺2 3 1
//
////�����3 2 1
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

//дһ�����룺��ӡ100~200֮�������
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

//��ӡ1000�굽2000��֮�������
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

//���������������������������Լ��
//
//���磺
//
//���룺20 40
//
//�����20
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

//����Ļ�����9 * 9�˷��ھ���
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

//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ����ӡ�����
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