#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SingleListNode
{
	int data;
	struct SingleListNode* next;
}SLNode;

void SLPrint(SLNode* phead);// �������ӡ

void SLPushBack(SLNode** pphead, int n);// ������β��
void SLPushFront(SLNode** pphead, int n);// ������ͷ��
void SLPopBack(SLNode** pphead);// ������βɾ
void SLPopFront(SLNode** pphead);// ������ͷɾ

SLNode* SLFind(SLNode* phead, int n);
void SLInsert(SLNode** pphead, SLNode* pos, int n);//��posǰ�����
void SLErase(SLNode** pphead, SLNode* pos);//ɾ��posǰ���Ǹ�


void SLInsertAfter(SLNode* pos, int n);//��pos�������
void SLEraseAfter(SLNode* pos);//��pos����ɾ��

void SLDestory(SLNode** pphead);







