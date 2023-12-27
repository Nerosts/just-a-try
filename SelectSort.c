#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//void SelectSort(int* a, int n)//升序
//{
//	int minf = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if (a[minf] > a[j])
//			{
//				minf = j;
//			}
//		}
//		Swap(&a[minf], &a[i]);
//	}
//}

//void SelectSort(int* a, int n)//升序
//{
//	int begin = 0;//begin之前包括自己已经排好
//	int end = n - 1;//end之后包括自己已经排好
//	while (begin < end)
//	{
//		int minf = begin;
//		int maxf = end;
//		for (int i = begin+1 ; i <= end; i++)//开始选最大和最小
//		{
//			if (a[i] < a[minf])
//			{
//				minf = i;
//			}
//			if (a[i] > a[maxf])
//			{
//				maxf = i;
//			}
//		}
//		Swap(&a[begin], &a[minf]);
//		if (begin == maxf)
//		{
//			maxf = minf;
//		}
//		Swap(&a[end], &a[maxf]);
//		begin++;
//		end--;
//	}
//}

//void SelectSort(int* a, int n)
//{
//	int begin = 0, end = n - 1;
//
//	while (begin < end)
//	{
//		// [begin, end]
//		int mini = begin, maxi = begin;
//		for (int i = begin + 1; i <= end; i++)
//		{
//			if (a[i] > a[maxi])
//			{
//				maxi = i;
//			}
//
//			if (a[i] < a[mini])
//			{
//				mini = i;
//			}
//		}
//
//		Swap(&a[begin], &a[mini]);
//		// max如果被换走了，修正一下
//		if (maxi == begin)
//		{
//			maxi = mini;
//		}
//
//		Swap(&a[end], &a[maxi]);
//
//		++begin;
//		--end;
//	}
//}

//void SelectSort(int* a, int n)//升序
//{
//	int minf = 0;
//	for (int i = 0; i < n-1; i++)
//	{
//		for (int j = i; j < n; j++)
//		{
//			if (a[minf] > a[j])
//			{
//				minf = j;
//			}
//		}
//		Swap(&a[minf], &a[i]);
//	}
//}

void SelectSort(int* a, int n)//升序
{
	int begin = 0, end = n - 1;
	while (begin < end)	//begin=end时就已经排好了
	{
		int mini = begin, maxi = begin;//不知道会指向哪里，所以要每次都初始化
		for (int i = begin + 1; i <= end; i++)//从begin到end找最大和最小
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[begin], &a[mini]);//最小跟begin换
		if (begin == maxi)//有可能begin位置就是此时最大的，maxi=begin，要是交换了，maxi值就不对了
		{
			maxi = mini;//让maxi仍是最大的数据的索引（此时数据被换到mini所指）
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}

}



int main()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	printf("排序前：");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	printf("排序后：");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}