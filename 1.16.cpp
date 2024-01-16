#define _CRT_SECURE_NO_WARNINGS 1
void _MergeSort(int* a, int* tmp, int left, int right)//���±꣬����ֵ
{
	if (left >= right)//ֻ��һ��Ԫ�ػ򲻴�������������ݹ�ֹͣ
	{
		return;
	}
	int mid = (left + right) / 2;//�ֳ������֣��ֱ�������ٽ��й鲢
	// [begin, mid][mid+1, end]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);//�������ֶ�������
	//��ʼ�鲢���鲢����tmp�������ͬλ�ã��ٿ�����ȥ

	int left1 = left; int right1 = mid;//��һ�����������
	int left2 = mid + 1; int right2 = right;//�ڶ������������
	int index = left;//���������Ǵ�left��ʼ�ģ�left��index���ǵ���ͬ������

	while (left1 <= right1 && left2 <= right2)//�����ȣ�С�ķŽ�ȥ
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
	}//��һ�������ˣ�ʣ�µ�һ����ֱ�ӷ�
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
	}//���ˣ�tmp���Ѿ��鲢�ɹ������������ƻ�a��
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}

void MergeSort(int* a, int n)
{
	//����һ����ʱ����
	int tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, tmp, 0, n - 1);//�Ӻ�����������ݹ鲻�ã��ж�̬����
	free(tmp);
}

int main()
{
	int a[] = { 10,6,7,1,3,9,4,2 };
	//MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));//������ӡ�����
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}
