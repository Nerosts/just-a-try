#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//void InsertionSort(int* a, int n)
//{
//	for (int i = 1; i < n; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (a[i] < a[j])
//			{
//				Swap(&a[i], &a[j]);
//			}
//		}
//	}
//}

void InsertionSort(int* a, int n)//升序
{
	for (int i = 0; i <= n - 2; i++)
	{
		int end = i;//用来标记，<=end的都已经排好了，该end+1排了
		int tmp = a[end + 1];//保存一下，后面可能会被覆盖
		while (end >= 0)//用来把比tmp大的向后移，中间就有空位了
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];//要是>tmp那就向后移动，也是覆盖发生
			}
			else
			{
				break;
			}
			end--;//end往前走
		}
		a[end + 1] = tmp;//放到空位，
	}

}

int main()
{
	int a[10] = { 2,5,6,1,8,9,10,12,56,73 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	InsertionSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}