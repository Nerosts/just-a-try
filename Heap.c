#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HInit(HP* php)
{
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HDestroy(HP* php)
{
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void sweap(HPDataType* a, HPDataType* b)
{
	HPDataType t = *a;
	*a = *b;
	*b = t;
}

void AdjustUp(HPDataType* a, int child)//'child' means the index of new 
{
	assert(a);//多余的
	int father = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[father])
		{
			sweap(&a[child], &a[father]);
			child = father;
			father = (father - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)//the prime thing is to check whether the capacity is full
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);

}

void AdjustDown(HPDataType* a,int size, int father)
{
	int child = father * 2 + 1;

	while (child < size)
	{	
		if (child+1<size && a[child + 1] < a[child])
		{
		child++;
		}

		if (a[father] > a[child])
		{
			sweap(&a[father], &a[child]);
			father = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	sweap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//开始下移
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}