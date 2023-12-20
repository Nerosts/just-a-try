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

void SLPrint(SLNode* phead);// 单链表打印

void SLPushBack(SLNode** pphead, int n);// 单链表尾插
void SLPushFront(SLNode** pphead, int n);// 单链表头插
void SLPopBack(SLNode** pphead);// 单链表尾删
void SLPopFront(SLNode** pphead);// 单链表头删

SLNode* SLFind(SLNode* phead, int n);
void SLInsert(SLNode** pphead, SLNode* pos, int n);//在pos前面插入
void SLErase(SLNode** pphead, SLNode* pos);//删除pos前面那个


void SLInsertAfter(SLNode* pos, int n);//在pos后面插入
void SLEraseAfter(SLNode* pos);//在pos后面删除

void SLDestory(SLNode** pphead);







