#define _CRT_SECURE_NO_WARNINGS 1
#define N 7
typedef int SLDataTypt;
struct SeqList
{
	int a[N];//数组长度固定
	int size;//有效数据的个数
			//因为数组长度固定，也不需要capacity来表示容积
};