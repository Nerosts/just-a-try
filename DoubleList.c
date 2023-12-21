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
	// phead               tail  newnode  位置展示
	newnode->next = phead;
	phead->prev = newnode;

	newnode->prev = tail;
	tail->next = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//只有哨兵位时不能删
	LTNode* tail = phead->prev;
	LTNode* pretail = tail->prev;
	// phead               pretail  tail  位置展示
	free(tail);
	tail = NULL;
	phead->prev = pretail;
	pretail->next = phead;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = CreateLTNode(x);
	//phead   newnode  firest                tail  位置展示
	newnode->next = phead->next;
	phead->next->prev = newnode;

	newnode->prev = phead;
	phead->next = newnode;
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//只有哨兵位时不能删
	LTNode* first = phead->next;
	LTNode* second = first->next;
	//phead    first   second             tail  位置展示
	free(first);
	first = NULL;

	phead->next = second;
	second->prev = phead;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	assert(phead->next != phead);//只有哨兵位时没必要查
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
	//pre  newnode   pos             tail  位置展示
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
	//pre    pos   next          tail  位置展示
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
	LTInsert(phead, x);//尾插就是在phead前插入
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
	LTInsert(phead->next, x);//头插就是插入到phead的下一个
}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->next);
}