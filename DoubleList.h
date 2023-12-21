#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;//��һ���ڵ�
	struct ListNode* prev;//��һ���ڵ�
	LTDataType val;//����
}LTNode;

LTNode* LTInit();//��ʼ��
void LTPrint(LTNode* phead);//��ӡ����

void LTPushBack(LTNode* phead, LTDataType x);//β��
void LTPopBack(LTNode* phead);//βɾ
void LTPushFront(LTNode* phead, LTDataType x);//ͷ��
void LTPopFront(LTNode* phead);//ͷɾ

LTNode* LTFind(LTNode* phead, LTDataType x);//����
void LTInsert(LTNode* pos, LTDataType x);//��posǰ����
void LTErase(LTNode* pos);//ɾ��pos

void LTDestroy(LTNode* phead);//����
