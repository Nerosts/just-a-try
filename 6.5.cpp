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
////一次排序
//int OneSort1(int* a, int left, int right)//使keyi位置的元素处于正确的位置上
//{
//	int keyi = left;
//	while (left < right)
//	{
//		while (a[right] >= a[keyi] && left < right)//右边先走
//		{
//			right--;
//		}
//		while (a[left] <= a[keyi] && left < right)//左侧找大的
//		{
//			left++;
//		}
//		Swap(&a[left], &a[right]);//找到一个大和一个小的就交换
//	}
//	Swap(&a[keyi], &a[left]);//把keyi放相遇位置
//	return left;//返回相遇的索引
//}
//
//void QuickSort(int* a, int begin, int end)//升序
//{
//	if (begin >= end)
//	{
//		return;
//	}
//	int keyi = OneSort1(a, begin, end);//找到keyi索引，才能分左右
//	QuickSort(a, begin, keyi - 1);//左侧
//	QuickSort(a, keyi + 1, end);//右侧
//}
//
////-----------------------------------------------------------------
//void InsertionSort(int* a, int n)//升序
//{
//	for (int i = 0; i <= n - 2; i++)
//	{
//		int end = i;//用来标记，<=end的都已经排好了，该end+1排了
//		int tmp = a[end + 1];//保存一下，后面可能会被覆盖
//		while (end >= 0)//用来把比tmp大的向后移，中间就有空位了
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];//要是>tmp那就向后移动，也是覆盖发生
//			}
//			else
//			{
//				break;
//			}
//			end--;//end往前走
//		}
//		a[end + 1] = tmp;//放到空位，
//	}
//
//}
//
////-----------------------------------------------------------------
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)//最外层循环用来减小gap
//	{
//		gap = gap / 3 + 1;//保证最后一个gap=1；1或2来除3是0
//		for (int i = 0; i < n - gap; i++)//第二层循环用来使整个数组以子序列为单位进行插入排序
//		{
//			int end = i;//需要end最初指向各子序列的头
//			int tmp = a[end + gap];//储存下一个需要排的
//			while (end >= 0)//第三次循环是针对这个tmp，看插在哪内进行插入排序（找空位）
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];//end处的值后移到子序列中的下一个
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;//放进空位
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
//void _MergeSort(int* a, int* tmp, int left, int right)//是下标，不是值
//{
//	if (left >= right)//只有一个元素或不存在这样的区间递归停止
//	{
//		return;
//	}
//	int mid = (left + right) / 2;//分成两部分，分别有序后再进行归并
//	// [begin, mid]   [mid+1, end]
//	_MergeSort(a, tmp, left, mid);
//	_MergeSort(a, tmp, mid + 1, right);
//
//	int left1 = left; int right1 = mid;//第一个数组的两端
//	int left2 = mid + 1; int right2 = right;//第二个数组的两端
//	int index = left;//两个数组是从left开始的，left给index就是到tmp的相同区间上
//
//	while (left1 <= right1 && left2 <= right2)//两个比，小的放进去
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
//	}//有一个排完了，剩下的一个就直接放
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
//	}//到此，tmp内已经归并成功，接下来复制回a中
//	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//}
//
//void MergeSort(int* a, int n)
//{
//	//创建一个临时数组
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	_MergeSort(a, tmp, 0, n - 1);//子函数，在这里递归不好，有动态开辟
//	free(tmp);
//}
//
////-----------------------------------------------------------------
//
//struct Tree
//{
//	char data;//这里我指明放char了
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
//// 创建二叉树
//Tree* CreateTree(int& i, const char* arr)
//{
//	if (arr[i] == '#' || arr[i] == '\0')//没了和碰到#都停
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
//// 计算二叉树深度
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
//// 计算叶子节点个数
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
//	cout << "输入二叉树: ";
//	cin.getline(arr, 100);
//	Tree* root = CreateTree(i, arr);
//
//	cout << "高度: " << Depth(root) << endl;
//	cout << "叶子节点数量: " << CountLeaves(root) << endl;
//
//	return 0;
//}