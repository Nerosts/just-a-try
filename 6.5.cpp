//#define _CRT_SECURE_NO_WARNINGS 1
//
#include<iostream>
#include<list>
#include<stdlib.h>
#include<assert.h>
using namespace std;

list<int>& test()
{
	list<int> lt = { 1,2 };
	return lt;
}

int main()
{
	list<int> ret=test();
	return 0;
}
//
//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
////һ������
//int OneSort1(int* a, int left, int right)//ʹkeyiλ�õ�Ԫ�ش�����ȷ��λ����
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (a[right] >= a[keyi] && left < right)//�ұ�����
//		{
//			right--;
//		}
//		while (a[left] <= a[keyi] && left < right)//����Ҵ��
//		{
//			left++;
//		}
//		Swap(&a[left], &a[right]);//�ҵ�һ�����һ��С�ľͽ���
//	}
//	Swap(&a[keyi], &a[left]);//��keyi������λ��
//	return left;//��������������
//}
//
//void QuickSort(int* a, int begin, int end)//����
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int keyi = OneSort1(a, begin, end);//�ҵ�keyi���������ܷ�����
//	QuickSort(a, begin, keyi - 1);//���
//	QuickSort(a, keyi + 1, end);//�Ҳ�
//}
//
////-----------------------------------------------------------------
//void InsertionSort(int* a, int n)//����
//{
//	for (int i = 0; i <= n - 2; i++)
//	{
//		int end = i;//������ǣ�<=end�Ķ��Ѿ��ź��ˣ���end+1����
//		int tmp = a[end + 1];//����һ�£�������ܻᱻ����
//		while (end >= 0)//�����ѱ�tmp�������ƣ��м���п�λ��
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];//Ҫ��>tmp�Ǿ�����ƶ���Ҳ�Ǹ��Ƿ���
//			}
//			else
//			{
//				break;
//			}
//			end--;//end��ǰ��
//		}
//		a[end + 1] = tmp;//�ŵ���λ��
//	}
//
//}
//
////-----------------------------------------------------------------
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)//�����ѭ��������Сgap
//	{
//		gap = gap / 3 + 1;//��֤���һ��gap=1��1��2����3��0
//		for (int i = 0; i < n - gap; i++)//�ڶ���ѭ������ʹ����������������Ϊ��λ���в�������
//		{
//			int end = i;//��Ҫend���ָ��������е�ͷ
//			int tmp = a[end + gap];//������һ����Ҫ�ŵ�
//			while (end >= 0)//������ѭ����������tmp�����������ڽ��в��������ҿ�λ��
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];//end����ֵ���Ƶ��������е���һ��
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;//�Ž���λ
//		}
//
//
//	}
//}
////-----------------------------------------------------------------
//void BobbleSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//			}
//		}
//	}
//}
//
////-----------------------------------------------------------------
//
//void _MergeSort(int* a, int* tmp, int left, int right)//���±꣬����ֵ
//{
//	if (left >= right)//ֻ��һ��Ԫ�ػ򲻴�������������ݹ�ֹͣ
//	{
//		return;
//	}
//	int mid = (left + right) / 2;//�ֳ������֣��ֱ�������ٽ��й鲢
//	// [begin, mid]   [mid+1, end]
//	_MergeSort(a, tmp, left, mid);
//	_MergeSort(a, tmp, mid + 1, right);
//
//	int left1 = left; int right1 = mid;//��һ�����������
//	int left2 = mid + 1; int right2 = right;//�ڶ������������
//	int index = left;//���������Ǵ�left��ʼ�ģ�left��index���ǵ�tmp����ͬ������
//
//	while (left1 <= right1 && left2 <= right2)//�����ȣ�С�ķŽ�ȥ
//	{
//		if (a[left1] < a[left2])
//		{
//			tmp[index] = a[left1];
//			index++;
//			left1++;
//		}
//		else
//		{
//			tmp[index] = a[left2];
//			index++;
//			left2++;
//		}
//	}//��һ�������ˣ�ʣ�µ�һ����ֱ�ӷ�
//	while (left1 <= right1)
//	{
//		tmp[index] = a[left1];
//		index++;
//		left1++;
//	}
//	while (left2 <= right2)
//	{
//		tmp[index] = a[left2];
//		index++;
//		left2++;
//	}//���ˣ�tmp���Ѿ��鲢�ɹ������������ƻ�a��
//	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//}
//
//void MergeSort(int* a, int n)
//{
//	//����һ����ʱ����
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	_MergeSort(a, tmp, 0, n - 1);//�Ӻ�����������ݹ鲻�ã��ж�̬����
//	free(tmp);
//}
//
////-----------------------------------------------------------------
//
//struct Tree
//{
//	char data;//������ָ����char��
//	struct Tree* Lchild;
//	struct Tree* Rchild;
//
//	Tree(const char& d)
//	{
//		data = d;
//		Lchild = Rchild = NULL;
//	}
//};
//
//// ����������
//Tree* CreateTree(int& i, const char* arr)
//{
//	if (arr[i] == '#' || arr[i] == '\0')//û�˺�����#��ͣ
//	{
//		i++;
//		return NULL;
//	}
//
//	Tree* T = new Tree(arr[i++]);
//	T->Lchild = CreateTree(i, arr);
//	T->Rchild = CreateTree(i, arr);
//	return T;
//}
//
//// ������������
//int Depth(Tree* T)
//{
//	if (T == NULL)
//		return 0;
//
//	int leftDepth = Depth(T->Lchild);
//	int rightDepth = Depth(T->Rchild);
//	return max(leftDepth, rightDepth) + 1;
//}
//
//// ����Ҷ�ӽڵ����
//int CountLeaves(Tree* root)
//{
//	if (root == NULL)
//		return 0;
//	if (root->Lchild == NULL && root->Rchild == NULL)
//		return 1;
//	return CountLeaves(root->Lchild) + CountLeaves(root->Rchild);
//}
//
//int main()
//{
//	int i = 0;
//	char arr[100];
//	cout << "���������: ";
//	cin.getline(arr, 100);
//	Tree* root = CreateTree(i, arr);
//
//	cout << "�߶�: " << Depth(root) << endl;
//	cout << "Ҷ�ӽڵ�����: " << CountLeaves(root) << endl;
//
//	return 0;
//}