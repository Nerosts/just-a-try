#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>
//
//
//void test1(int n, int* arr)
//{
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = rand() % n + 1;
//		if (i > 1 && arr[i] == arr[i - 1])
//		{
//			i--;
//			continue;
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		printf("%-5d", arr[i]);
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	/*srand((unsigned)time(localtime));*/
//
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(n * sizeof(int));
//
//
//
//	for (int i = 0; i < n*n; i++)
//	{
//		test1(n, arr);
//	}
//	
//	return 0;
//}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[10] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		while (n)
		{
			for (int i = 1; i <= n; i++)
			{
				switch (n % 10)
				{
				case 0:
					arr[0] = arr[0] + 1;
					break;
				case 1:
					arr[1] = arr[1] + 1;
					break;
				case 2:
					arr[2] = arr[2] + 1;
					break;
				case 3:
					arr[3] = arr[3] + 1;
					break;
				case 4:
					arr[4] = arr[4] + 1;
					break;
				case 5:
					arr[5] = arr[5] + 1;
					break;
				case 6:
					arr[6] = arr[6] + 1;
					break;
				case 7:
					arr[7] = arr[7] + 1;
					break;
				case 8:
					arr[8] = arr[8] + 1;
					break;
				case 9:
					arr[9] = arr[9] + 1;
					break;
				}
				n = n / 10;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}

//int cmp(const void* a, void* b)
//{
//	return *(int*)a - *(int*)b;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(int), cmp);
//	printf("%d", arr[n - 1] - arr[0]);
//	return 0;
//}
//void add(int x, int y)
//{
//	printf("%d+%d=%d\n", x, y, x + y);
//}
//
//void jian(int x, int y)
//{
//	printf("%d-%d=%d\n", x, y, x - y);
//}
//
//void mul(int x, int y)
//{
//	printf("%d*%d=%d\n", x, y, x * y);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	while (n--)
//	{
//		while (n--)
//		{
//			char choice = '0';
//			scanf("%c", &choice);
//			int x = 0;
//			int y = 0;
//			scanf("%d %d", &x, &y);
//			getchar();
//			switch (choice)
//			{
//			case 'a':
//				add(x, y);
//				break;
//			case 'b':
//				jian(x, y);
//				break;
//			case 'c':
//				mul(x, y);
//				break;
//			}
//		}
//	}
//	return 0;
//}

