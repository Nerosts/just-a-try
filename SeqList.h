#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//the number of valid data
	int capacity;//the size of volumetric space
}SL;

void SLInit(SL* ps); //��ʼ��
void SLDestroy(SL* ps);//����
void SLPrint(SL* ps);//��ӡ

void SLPushBack(SL* ps, SLDataType x);//β��
void SLPushFront(SL* ps, SLDataType x);//ͷ��
void SLPopFront(SL* ps);//ͷɾ
void SLPopBack(SL* ps);//βɾ

// ˳������
int SLFind(SL* ps, SLDataType x);//�����±�����
// ˳�����posλ�ò���x
void SeqListInsert(SL* ps, int pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SL* ps, int pos);







