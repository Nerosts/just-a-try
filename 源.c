#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubbleSort(int arr[], int se)
{
	for (int i = 0; i < se - 1; i++)//n��Ԫ������n-1�����OK�ˣ����һ���Զ��ź���
	{
		for (int j = 0; j < se - 1 - i; j++)//ÿ�ź�һ��������ٱ�һ�Σ����Լ�ȥi
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main()
{
	int arr[] = { 5,2,9,1,3 };
	int se = sizeof(arr) / sizeof(arr[0]);//���õķ����������鳤�ȣ�
	//��ʼ��ӡ����ǰ����
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//���ú�����������
	bubbleSort(arr, se);
	//��ӡ������
	for (int i = 0; i < se; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}