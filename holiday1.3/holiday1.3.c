#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
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

//����ϿεĲ�������Ϸ
//void menu()
//{
//	printf("*****************\n");
//	printf("*****1.��ʼ******\n");
//	printf("*****0.����******\n");
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
//			printf("�´���");
//		}
//		else if (guess < target)
//		{
//			printf("��С��");
//		}
//		else {
//			printf("��ϲ��¶���");
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
//		printf("��ѡ��\n");
//		menu();
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("������Ϸ");
//		default:
//			printf("ѡ���������ѡ��");
//			break;
//		}
//	}
//	return 0;
//}
//
//��д������һ���������������в��Ҿ����ĳ����
//
//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����

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
		printf("û���ҵ�");
	}
	else
		printf("�ҵ��ˣ��±���%d", target-1);
}
