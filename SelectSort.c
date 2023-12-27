#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//void SelectSort(int* a, int n)//����
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

//void SelectSort(int* a, int n)//����
//{
//	int begin = 0;//begin֮ǰ�����Լ��Ѿ��ź�
//	int end = n - 1;//end֮������Լ��Ѿ��ź�
//	while (begin < end)
//	{
//		int minf = begin;
//		int maxf = end;
//		for (int i = begin+1 ; i <= end; i++)//��ʼѡ������С
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
//		// max����������ˣ�����һ��
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

//void SelectSort(int* a, int n)//����
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

void SelectSort(int* a, int n)//����
{
	int begin = 0, end = n - 1;
	while (begin < end)	//begin=endʱ���Ѿ��ź���
	{
		int mini = begin, maxi = begin;//��֪����ָ���������Ҫÿ�ζ���ʼ��
		for (int i = begin + 1; i <= end; i++)//��begin��end��������С
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
		Swap(&a[begin], &a[mini]);//��С��begin��
		if (begin == maxi)//�п���beginλ�þ��Ǵ�ʱ���ģ�maxi=begin��Ҫ�ǽ����ˣ�maxiֵ�Ͳ�����
		{
			maxi = mini;//��maxi�����������ݵ���������ʱ���ݱ�����mini��ָ��
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}

}



int main()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	printf("����ǰ��");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	SelectSort(a, sizeof(a) / sizeof(int));
	printf("�����");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}