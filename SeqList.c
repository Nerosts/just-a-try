#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* new = realloc(ps->a,sizeof(SLDataType) * newcapacity);
		if (new == NULL)
		{
			perror("realloc");
			return -1;
		}
		ps->a = new;
		ps->capacity = newcapacity;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);//检查此时容积是否存满
	ps->a[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL* ps, SLDataType x) //将所有元素向后迁移一个，把第一个位置空出来
{
	assert(ps);
	CheckCapacity(ps);
	memmove(ps->a + 1, ps->a, sizeof(SLDataType) * ps->size);
	ps->a[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps)//整体向前偏移
{
	assert(ps);
	assert(ps->size > 0);
	memmove(ps->a, ps->a+1, sizeof(SLDataType) * ps->size);
	ps->size--;
}

void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	CheckCapacity(ps);
	memmove(ps->a + pos + 1, ps->a + pos, sizeof(SLDataType) * (ps->size - pos));
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	int start = pos;
	while (start < ps->size)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}







