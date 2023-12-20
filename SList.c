#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SLPrint(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur != NULL)//与while(cur)同样的效果
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

SLNode* CreateNode(int n)
{
	SLNode* newNode= (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
	{
		perror("malloc error");
		return -1;
	}
	newNode->data = n;
	newNode->next = NULL;
	return newNode;
}

void SLPushBack(SLNode** pphead, int n)
{
	assert(pphead);

	SLNode* newNode = CreateNode(n);//先把节点搞好
	//先考虑一下没有节点的情况
	if (*pphead == NULL)
	{
		*pphead = newNode;  //这就是传二级指针的原因：
		                   //我们要改变 SLNode* phead本身的指向，就把他地址传过来
		                  //当我们只是要改变指向的结构体里的内容时只要传SLNode* phead就行了
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)//找到最后一个节点
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void SLPushFront(SLNode** pphead, int n)
{
	assert(pphead);

	SLNode* newNode = CreateNode(n);//先把节点搞好
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		newNode->next = (*pphead)->next;
		(*pphead)->next = newNode;
	}
	//或者
	//newNode->next = (*pphead);
	//*pphead = newNode;
}

void SLPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);//防止一个都没有还删
	if ((*pphead)->next == NULL)//只有一个
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找到倒数第二个
		SLNode* pre_tail = *pphead;
		while (pre_tail->next->next != NULL)
		{
			pre_tail = pre_tail->next;
		}
		free(pre_tail->next);
		pre_tail->next = NULL;
	}
}

void SLPopFront(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);//防止一个都没有还删

	SLNode* first = (*pphead)->next;//一个和多个都适用
	free(*pphead);
	*pphead = first;
}

SLNode* SLFind(SLNode* phead, int n)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur != NULL)//与while(cur)同样的效果
	{
		if (cur->data == n)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLInsert(SLNode** pphead, SLNode* pos, int n)//在pos前面插入
{
	assert(pphead);
	assert(pos);
	SLNode* cur = *pphead;
	if (*pphead == pos)//在第一个节点前面插入
	{
		// 头插
		SLTPushFront(pphead, n);
	}
	else
	{
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		SLNode* newNode = CreateNode(n);
		newNode->next = cur->next;
		cur->next = newNode;
	}
}

void SLErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead != pos);//防止前面没有
	SLNode* cur = *pphead;
	SLNode* pre_cur = *pphead;
	while (cur->next != pos)
	{
		pre_cur = cur;
		cur = cur->next;
	}
	pre_cur->next = pos;
	free(cur);
	cur = NULL;
}

void SLInsertAfter(SLNode* pos, int n)
{
	assert(pos);
	SLNode* newNode =CreateNode(n);
	newNode->next = pos->next;
	pos->next = newNode;
}

void SLEraseAfter(SLNode* pos)
{
	assert(pos);
	SLNode* next = pos->next->next;
	free(pos->next);
	pos->next = NULL;
	pos->next = next;
}

void SLDestory(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	SLNode* next = *pphead;
	while (cur!=NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}



