#define _CRT_SECURE_NO_WARNINGS 1
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
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
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

}




