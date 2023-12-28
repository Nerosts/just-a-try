#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void STInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

void STDestroy(ST* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top + 1)//判断有没有满
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		STDataType* new = (STDataType*)realloc(ps->a, sizeof(ST) * newCapacity);
		assert(new);
		ps->a = new;
		ps->capacity = newCapacity;
	}
	ps->top++;
	ps->a[ps->top] = x;
}

void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top >= 0);//确保不为空
	ps->top--;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top >= 0);
	return ps->a[ps->top];
}

bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == -1;
}

int STSize(ST* ps)
{
	assert(ps);
	return ps->top + 1;
}