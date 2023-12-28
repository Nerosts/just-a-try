#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>

//int OneSort1(int* a, int left, int right) {
//	int keyi = left; // 选取第一个元素作为基准值
//
//	while (left < right) {
//		while (left < right && a[right] >= a[keyi]) 
//		{
//			right--;
//		}
//		if (left < right) 
//		{
//			a[left] = a[right];
//			left++;
//		}
//
//		while (left < right && a[left] <= a[keyi]) 
//		{
//			left++;
//		}
//		if (left < right) 
//		{
//			a[right] = a[left];
//			right--;
//		}
//	}
//
//	a[left] = keyi;
//	return left;
//}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int GetMid(int* a,int left, int right)//找中间的
{
	// a[left]      a[mid]           a[right]
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])  // mid是最大值
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[left] < a[right])
		{
			return left;
		}
		else if (a[mid] < a[right])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}

int OneSort1(int* a, int left, int right)//使keyi位置的元素处于正确的位置上
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);//现在left处是三者的中间值了
	//左边第一个为key，右边先走才能保证相遇处比啊a[keyi]小
	int keyi = left;
	while (left < right)
	{
		while (a[right] >= a[keyi] && left < right)//右边先走
		{
			right--;
		}
		while (a[left] <= a[keyi] && left < right)//左侧找大的
		{
			left++;
		}
		Swap(&a[left], &a[right]);//找到一个大和一个小的就交换
	}
	Swap(&a[keyi], &a[left]);//把keyi放相遇位置
	return left;//返回相遇的索引
}

int OneSort2(int* a, int left, int right)//挖坑
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);//现在left处是三者的中间值了

	int key = a[left];//保存基准元素
	int hole = left;//储存坑下标
	while (left < right)
	{
		while (a[right] >= key && left < right)//右边先走
		{
			right--;
		}//找到了就去赋值到第一个“坑”
		a[hole] = a[right];
		hole = right;//更新坑
		while (a[left] <= key && left < right)//左侧找大的
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	Swap(&key, &a[left]);//把keyi放相遇位置
	return left;//返回相遇的索引
}

//int OneSort3(int* a, int left, int right)//挖坑
//{
//	int mid = GetMid(a, left, right);
//	Swap(&a[mid], &a[left]);//现在left处是三者的中间值了
//
//	int key = a[left];//保存基准元素
//	while (left < right)
//	{
//		while (a[right] >= key && left < right)//右边先走
//		{
//			right--;
//		}
//		if (left < right)//找到了就去赋值到第一个“坑”
//		{
//			a[left] = a[right];//坑赋值后，向后+1
//			left++;
//		}
//		while (a[left] <= key && left < right)//左侧找大的
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			a[right] = a[left];
//			right--;
//		}
//	}
//	Swap(&key, &a[left]);//把keyi放相遇位置
//	return left;//返回相遇的索引
//}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
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

int OneSort3(int* a, int left, int right)//挖坑
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);

	int keyi = left;
	int pre = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi])
		{
			pre++;
			Swap(&a[cur], &a[pre]);
		}
		cur++;
	}
	Swap(&a[pre], &a[keyi]);
	return pre;
}

void QuickSort(int* a, int begin, int end)//升序
{
	if (begin >= end)
	{
		return;
	}

	if ((end - begin + 1) > 10)
	{
		// [begin, keyi-1] keyi [keyi+1, end]
		int keyi = OneSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);
		QuickSort(a, keyi + 1, end);
	}
	else
	{
		//用插入排序
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSortNonR(int* a, int begin, int end)//利用栈，先想好先排左侧再排右侧
{
	ST st;
	STInit(&st);
	STPush(&st,end);//把各个区间的两侧的索引（整形）插入进Stack中
	STPush(&st,begin);//栈（后进先出），先排左侧后入左
	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);
		int right = STTop(&st);
		STPop(&st);

		int keyi = OneSort1(a, left, right);//得到基准元素下标
		// [begin, keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < right)//等于说明就一个，没必要
		{
			STPush(&st, right);
			STPush(&st, keyi);
		}
		if (left < keyi-1)
		{
			STPush(&st, keyi-1);
			STPush(&st, left);
		}
	}
	STDestroy(&st);
}

void BobbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}

int main()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	printf("排序前：");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	BobbleSort(a,sizeof(a) / sizeof(int)-1);
	printf("排序后：");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}