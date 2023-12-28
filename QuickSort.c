#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include<stdio.h>

//int OneSort1(int* a, int left, int right) {
//	int keyi = left; // ѡȡ��һ��Ԫ����Ϊ��׼ֵ
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

int GetMid(int* a,int left, int right)//���м��
{
	// a[left]      a[mid]           a[right]
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])  // mid�����ֵ
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

int OneSort1(int* a, int left, int right)//ʹkeyiλ�õ�Ԫ�ش�����ȷ��λ����
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);//����left�������ߵ��м�ֵ��
	//��ߵ�һ��Ϊkey���ұ����߲��ܱ�֤�������Ȱ�a[keyi]С
	int keyi = left;
	while (left < right)
	{
		while (a[right] >= a[keyi] && left < right)//�ұ�����
		{
			right--;
		}
		while (a[left] <= a[keyi] && left < right)//����Ҵ��
		{
			left++;
		}
		Swap(&a[left], &a[right]);//�ҵ�һ�����һ��С�ľͽ���
	}
	Swap(&a[keyi], &a[left]);//��keyi������λ��
	return left;//��������������
}

int OneSort2(int* a, int left, int right)//�ڿ�
{
	int mid = GetMid(a, left, right);
	Swap(&a[mid], &a[left]);//����left�������ߵ��м�ֵ��

	int key = a[left];//�����׼Ԫ��
	int hole = left;//������±�
	while (left < right)
	{
		while (a[right] >= key && left < right)//�ұ�����
		{
			right--;
		}//�ҵ��˾�ȥ��ֵ����һ�����ӡ�
		a[hole] = a[right];
		hole = right;//���¿�
		while (a[left] <= key && left < right)//����Ҵ��
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	Swap(&key, &a[left]);//��keyi������λ��
	return left;//��������������
}

//int OneSort3(int* a, int left, int right)//�ڿ�
//{
//	int mid = GetMid(a, left, right);
//	Swap(&a[mid], &a[left]);//����left�������ߵ��м�ֵ��
//
//	int key = a[left];//�����׼Ԫ��
//	while (left < right)
//	{
//		while (a[right] >= key && left < right)//�ұ�����
//		{
//			right--;
//		}
//		if (left < right)//�ҵ��˾�ȥ��ֵ����һ�����ӡ�
//		{
//			a[left] = a[right];//�Ӹ�ֵ�����+1
//			left++;
//		}
//		while (a[left] <= key && left < right)//����Ҵ��
//		{
//			left++;
//		}
//		if (left < right)
//		{
//			a[right] = a[left];
//			right--;
//		}
//	}
//	Swap(&key, &a[left]);//��keyi������λ��
//	return left;//��������������
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

int OneSort3(int* a, int left, int right)//�ڿ�
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

void QuickSort(int* a, int begin, int end)//����
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
		//�ò�������
		InsertSort(a + begin, end - begin + 1);
	}
}

void QuickSortNonR(int* a, int begin, int end)//����ջ�������������������Ҳ�
{
	ST st;
	STInit(&st);
	STPush(&st,end);//�Ѹ����������������������Σ������Stack��
	STPush(&st,begin);//ջ������ȳ�����������������
	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);
		int right = STTop(&st);
		STPop(&st);

		int keyi = OneSort1(a, left, right);//�õ���׼Ԫ���±�
		// [begin, keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < right)//����˵����һ����û��Ҫ
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
	printf("����ǰ��");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	BobbleSort(a,sizeof(a) / sizeof(int)-1);
	printf("�����");
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}