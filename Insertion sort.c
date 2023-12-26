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

void InsertionSort(int* a, int n)//����
{
	for (int i = 0; i <= n - 2; i++)
	{
		int end = i;//������ǣ�<=end�Ķ��Ѿ��ź��ˣ���end+1����
		int tmp = a[end + 1];//����һ�£�������ܻᱻ����
		while (end >= 0)//�����ѱ�tmp�������ƣ��м���п�λ��
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];//Ҫ��>tmp�Ǿ�����ƶ���Ҳ�Ǹ��Ƿ���
			}
			else
			{
				break;
			}
			end--;//end��ǰ��
		}
		a[end + 1] = tmp;//�ŵ���λ��
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