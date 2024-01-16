#define _CRT_SECURE_NO_WARNINGS 1
void _MergeSort(int* a, int* tmp, int left, int right)//是下标，不是值
{
	if (left >= right)//只有一个元素或不存在这样的区间递归停止
	{
		return;
	}
	int mid = (left + right) / 2;//分成两部分，分别有序后再进行归并
	// [begin, mid][mid+1, end]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);//这两部分都有序啦
	//开始归并：归并到到tmp数组的相同位置，再拷贝回去

	int left1 = left; int right1 = mid;//第一个数组的两端
	int left2 = mid + 1; int right2 = right;//第二个数组的两端
	int index = left;//两个数组是从left开始的，left给index就是到相同区间上

	while (left1 <= right1 && left2 <= right2)//两个比，小的放进去
	{
		if (a[left1] < a[left2])
		{
			tmp[index] = a[left1];
			index++;
			left1++;
		}
		else
		{
			tmp[index] = a[left2];
			index++;
			left2++;
		}
	}//有一个排完了，剩下的一个就直接放
	while (left1 <= right1)
	{
		tmp[index] = a[left1];
		index++;
		left1++;
	}
	while (left2 <= right2)
	{
		tmp[index] = a[left2];
		index++;
		left2++;
	}//到此，tmp内已经归并成功，接下来复制回a中
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	//创建一个临时数组
	int tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, tmp, 0, n - 1);//子函数，在这里递归不好，有动态开辟
	free(tmp);
}

int main()
{
	int a[] = { 10,6,7,1,3,9,4,2 };
	//MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));//用来打印数组的
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}
