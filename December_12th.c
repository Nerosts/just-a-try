#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int test1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N-1; ++j)
		{
			++count;
		}
	}

	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	int M = 20;
	while (M--)
	{
		++count;
	}
}

void Fac(int N)
{
	if (N == 0)
		return 1;

	return Fac(N - 1) * N;
}

void test3()
{
	int count = 0;
	for (int k = 0; k < 100; ++k)
	{
		++count;
	}
}

void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}

int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin <= end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;//找到了返回下标
	}
	return -1;//没找到返回-1
}

int main()
{

	return 0;
}