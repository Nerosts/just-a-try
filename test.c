#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test1()
{
	HPDataType a[] = { 4,1,3,2,2 };
	HP hp;
	HInit(&hp);
	for (int i = 0; i < 5; i++)
	{
		HPush(&hp, a[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", hp.a[0]);
		HeapPop(&hp);
	}
}

int main()
{
	test1();
	return 0;
}

