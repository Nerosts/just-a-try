#define _CRT_SECURE_NO_WARNINGS 1
#include"DoubleList.h"

LTNode* CreateLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		return -1;
	}

	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//LTNode* LTInit()
//{
//	LTNode* a =CreateLTNode(-1);
//	a->next = a;
//	a->prev = a;
//	a->val = 0;
//	return a;
//}


void LTInit(LTNode** pphead)
{
	*pphead = CreateLTNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->prev = *pphead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead;
	while (cur->next != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("%d ", cur->val);
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = CreateLTNode(x);
	LTNode* tail = phead->prev;
	// phead               tail  newnode  λ��չʾ
	newnode->next = phead;
	phead->prev = newnode;

	newnode->prev = tail;
	tail->next = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//ֻ���ڱ�λʱ����ɾ
	LTNode* tail = phead->prev;
	LTNode* pretail = tail->prev;
	// phead               pretail  tail  λ��չʾ
	free(tail);
	tail = NULL;
	phead->prev = pretail;
	pretail->next = phead;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = CreateLTNode(x);
	//phead   newnode  firest                tail  λ��չʾ
	newnode->next = phead->next;
	phead->next->prev = newnode;

	newnode->prev = phead;
	phead->next = newnode;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//ֻ���ڱ�λʱ����ɾ
	LTNode* first = phead->next;
	LTNode* second = first->next;
	//phead    first   second             tail  λ��չʾ
	free(first);
	first = NULL;

	phead->next = second;
	second->prev = phead;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	assert(phead->next != phead);//ֻ���ڱ�λʱû��Ҫ��
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = CreateLTNode(x);
	LTNode* pre = pos->prev;
	//pre  newnode   pos             tail  λ��չʾ
	pre->next = newnode;
	newnode->prev = pre;

	newnode->next = pos;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* pre = pos->prev;
	LTNode* next = pos->next;
	//pre    pos   next          tail  λ��չʾ
	pre->next = next;
	next->prev = pre;
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur->next != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead, x);//β�������pheadǰ����
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->prev);
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead->next, x);//ͷ����ǲ��뵽phead����һ��
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->next);
}