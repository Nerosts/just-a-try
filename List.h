#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;

LTNode* LTInit();

void MYLTInit(LTNode** phead);

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* pHead, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(LTNode* pos, LTDataType x);

void ListErase(LTNode* pos);

void MYLTDestroy(LTNode** phead);