#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 1;
//	char* pa =(char*)&a;
//	if (*pa)
//	{
//		printf("xiao");
//	}
//	else
//	{
//		printf("da");
//	}
//	return 0;
//}

//int main()
//{
//	for (int a = 1; a <= 5; a++)
//	{
//		for (int b = 1; b <= 5; b++)
//		{
//			for (int c = 1; c <= 5; c++)
//			{
//				for (int d = 1; d <= 5; d++)
//				{
//					for (int e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//								break;
//							}
//						}
//							
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main()
//
//	{
//		char killer = 'A'; //����char���ͱ���killer,����ָʾ����
//		for (killer = 'A'; killer <= 'D'; killer++)
//		{
//			if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//			{
//				break;
//			}
//		}
//		printf("������:%c", killer);
//		return 0;
//	
//
//}
//��ӡ���������
int main()

{
	int data[9][9];//����һ��9��9�е�����
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			data[i][j] = 1;
	}
	for (int i = 2; i < 9; i++)
	{
		for (int j = 1; j < i; j++)
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];//��ǰ��=��һ�е���+��һ��ǰ�����
	}
	for (int i = 0; i < 9; i++)
	{
	
		for (int j = 0; j <= i; j++)//j<=i��ʾ��������½����ݣ���˼·��2
			printf("%6d", data[i][j]);
		printf("\n");//���������������
	}
	return 0;
}
