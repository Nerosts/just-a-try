#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}

void CountSort(int* a, int n)
{
	//先找最大最小，确定范围
	int max = a[0], min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count= (int*)calloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail");
		return;
	}
	//开始想count中累加了
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	//赋值覆盖
	int a_index = 0;
	for (int i = 0; i < range; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			a[a_index] = i + min;
			a_index++;
		}
	}
}

int main()
{
	int a[] = { 2,4,1,7,9 };
	CountSort(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}