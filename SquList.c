#define _CRT_SECURE_NO_WARNINGS 1
#include"SquList.h"

void SLInit(SL* s)
{
	s->a = NULL;
	s->size = 0;
	s->capacity = 0;
}

void SLPrint(SL* s)
{
	for (int i = 0; i < s->size; i++)
	{
		printf("%d ", s->a[i]);
	}
	printf("\n");
}

void SLDestroy(SL* s)
{
	if (s->a != NULL)
	{

		s->a = NULL;
		s->size = 0;
		s->capacity = 0;
	}
}

void SLCheck(SL* s)
{
	if (s->capacity == s->size)
	{
		s->capacity = s->capacity == 0 ? 4 : s->capacity * 2;
		SLDateType* ss = NULL;
		ss = (SLDateType*)realloc(ss, sizeof(SLDateType) * (s->capacity));
		if (ss != NULL)
		{
			s->a = ss;
		}
	}
}

void SLPushBack(SL* s, SLDateType x)
{
	SLCheck(s);
	s->a[s->size] = x;
	s->size++;
}

void SLPushFront(SL* s, SLDateType x)
{
	SLCheck(s);
	//ÕûÌåºóÒÆ
	memmove(s->a+1, s->a, sizeof(int) * (s->size));
	s->a[0] = x;
	s->size++;
}

void SLPopBack(SL* s)
{
	if (s->size > 0) {
		s->size--;
	}
	else
	{
		assert(s->size > 0);
	}
}

void SLPopFront(SL* s)
{
	assert(s->size > 0);
	memmove(s->a, s->a + 1, sizeof(int) * (s->size));
	s->size--;
}

void SLInsert(SL* s, int pos, SLDateType x)
{
	assert(s);
	assert(pos >= 0 && pos <= s->size);
	SLCheck(s);
	int end = s->size - 1;
	while (end >= pos)
	{
		s->a[end + 1] = s->a[end];
		end--;
	}
	s->a[pos] = x;
	s->size++;
}

void SLErease(SL* s, int pos, SLDateType x)
{
	assert(s);
	assert(pos >= 0 && pos < s->size);
	int start = pos+1;
	while (start < s->size)
	{
		s->a[start] = s->a[start+1];
	}
	s->size--;
}

int SLFind(SL* s, int pos, SLDateType x)
{
	for (int i = 0; i < s->size; i++)
	{
		if (x == s->a[i])
		{
			pos = i;
			return pos;
		}

	}
	return -1;
}