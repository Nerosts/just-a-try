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
//		char killer = 'A'; //定义char类型变量killer,用来指示凶手
//		for (killer = 'A'; killer <= 'D'; killer++)
//		{
//			if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//			{
//				break;
//			}
//		}
//		printf("凶手是:%c", killer);
//		return 0;
//	
//
//}
//打印出杨辉三角
int main()

{
	int data[9][9];//定义一个9行9列的数组
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			data[i][j] = 1;
	}
	for (int i = 2; i < 9; i++)
	{
		for (int j = 1; j < i; j++)
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1];//当前数=上一行的数+上一行前面的数
	}
	for (int i = 0; i < 9; i++)
	{
	
		for (int j = 0; j <= i; j++)//j<=i表示仅输出左下角数据，如思路中2
			printf("%6d", data[i][j]);
		printf("\n");//输出数组所有数据
	}
	return 0;
}
