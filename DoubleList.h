#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;//下一个节点
	struct ListNode* prev;//上一个节点
	LTDataType val;//数据
}LTNode;

LTNode* LTInit();//初始化
void LTPrint(LTNode* phead);//打印数据

void LTPushBack(LTNode* phead, LTDataType x);//尾插
void LTPopBack(LTNode* phead);//尾删
void LTPushFront(LTNode* phead, LTDataType x);//头插
void LTPopFront(LTNode* phead);//头删

LTNode* LTFind(LTNode* phead, LTDataType x);//查找
void LTInsert(LTNode* pos, LTDataType x);//在pos前插入
void LTErase(LTNode* pos);//删除pos

void LTDestroy(LTNode* phead);//销毁
