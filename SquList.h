#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDateType;
typedef struct SquList
{
	SLDateType* a;
	int size;
	int capacity;
}SL;

void SLInit(SL* s);

void SLPrint(SL* s);

void SLDestroy(SL* s);

void SLCheck(SL* s);

void SLPushBack(SL* s, SLDateType x);//βɾ
void SLPushFront(SL* s, SLDateType x);//β��
void SLPopBack(SL* s);//ͷɾ
void SLPopFront(SL* s);//ͷ��

int SLFind(SL* s, int pos, SLDateType x);
void SLInsert(SL* s,int pos, SLDateType x);
void SLErease(SL* s, int pos, SLDateType x);


