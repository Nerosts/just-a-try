#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

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

LTNode* LTInit()
{
	LTNode* phead = CreateLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void MYLTInit(LTNode** phead)
{
	*phead = CreateLTNode(-1);
	(*phead)->next = *phead;
	(*phead)->prev = *phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* tail = phead->prev;
	//LTNode* newnode = CreateLTNode(x);

	//// phead               tail  newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead->prev, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* pretail = tail->prev;
	free(tail);
	phead->prev = pretail;
	pretail->next = phead;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	//LTNode* newnode = CreateLTNode(x);

	//newnode->next = phead->next;
	//newnode->prev = phead;
	//phead->next->prev = newnode;
	//phead->next = newnode;

	ListInsert(phead->next, x);
}

void LTPopFront(LTNode* phead)
{
	assert(phead->next != phead->prev);
	LTNode* next = phead->next;
	phead->next = next->next;
	next->next->prev = phead;
	
	free(next);
	next = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = CreateLTNode(x);
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* pre = pos->prev;
	pre->prev->next = pos;
	pos->prev = pre->prev;
	free(pre);
	pre = NULL;
}

void MYLTDestroy(LTNode* phead)
{
	LTNode* cur = phead->next;
	while (cur)
	{
		if (cur->next == NULL)
		{
			free(cur);
			cur = NULL;
		}
		else
		{
			LTNode* next = cur->next;
			free(cur);
			cur = next;
		}
	}
}

