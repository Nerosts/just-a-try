#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void SInit(ST* pst)
{
	pst->a = NULL;
	pst->capacity = 0;
	pst->top = -1;
}

void SDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
}

void check(ST* pst)
{
	if (pst->capacity == pst->top+1)
	{
		pst->capacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		pst->a = realloc(pst->a, sizeof(ST) * pst->capacity);
	}
}

void SPush(ST* pst, int x)
{
	assert(pst);
	check(pst);
	pst->top++;
	(pst->a)[pst->top] = x;
}

void SPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

STDataType STop(ST* pst)
{
	assert(pst);
	assert(pst->top >=0);
	return (pst->a)[pst->top];
}

bool SEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}

int SSize(ST* pst)
{
	assert(pst);
	return pst->top + 1;
}