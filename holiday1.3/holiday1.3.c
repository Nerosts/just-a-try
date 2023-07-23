#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9 || i / 10 == 9)
//		{
//			count++;
//			printf("%d\n", i);
//		}
//
//	}
//	printf("%d", count);
//	return 0;
//}

//完成上课的猜数字游戏
//void menu()
//{
//	printf("*****************\n");
//	printf("*****1.开始******\n");
//	printf("*****0.结束******\n");
//	printf("*****************\n");
//}
//
//void game()
//{
//	int target = rand()%100+1;
//	int guess;
//	while (1) {
//		scanf("%d", &guess);
//		if (guess > target)
//		{
//			printf("猜大了");
//		}
//		else if (guess < target)
//		{
//			printf("猜小了");
//		}
//		else {
//			printf("恭喜你猜对了");
//			break;
//		}
//	}
//}
//
//
//
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int n = 1;
//	while (n)
//	{
//		printf("请选择：\n");
//		menu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("结束游戏");
//		default:
//			printf("选择错误，重新选择");
//			break;
//		}
//	}
//	return 0;
//}
//
//编写代码在一个整形有序数组中查找具体的某个数
//
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int target = 0;
	scanf("%d", &target);
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int flag = 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (arr[target] < arr[mid]) {
			right = mid;
		}
		else if (arr[target] > arr[mid]) {
			left = mid;
		}
		else {
			target = mid;
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("没有找到");
	}
	else
		printf("找到了：下标是%d", target-1);
}
