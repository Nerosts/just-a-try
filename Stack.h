#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	int* a;
	int top;
	int capacity;
}ST;

void SInit(ST* pst);
void SDestroy(ST* pst);

void SPush(ST* pst, int x);
void SPop(ST* pst);

STDataType STop(ST* pst);
bool SEmpty(ST* pst);
int SSize(ST* pst);


