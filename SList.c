#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void SLPrint(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur != NULL)//��while(cur)ͬ����Ч��
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

	SLNode* newNode = CreateNode(n);//�Ȱѽڵ���
	//�ȿ���һ��û�нڵ�����
	if (*pphead == NULL)
	{
		*pphead = newNode;  //����Ǵ�����ָ���ԭ��
		                   //����Ҫ�ı� SLNode* phead�����ָ�򣬾Ͱ�����ַ������
		                  //������ֻ��Ҫ�ı�ָ��Ľṹ���������ʱֻҪ��SLNode* phead������
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)//�ҵ����һ���ڵ�
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

void SLPushFront(SLNode** pphead, int n)
{
	assert(pphead);

	SLNode* newNode = CreateNode(n);//�Ȱѽڵ���
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		newNode->next = (*pphead)->next;
		(*pphead)->next = newNode;
	}
	//����
	//newNode->next = (*pphead);
	//*pphead = newNode;
}

void SLPopBack(SLNode** pphead)
{
	assert(pphead);
	assert(*pphead);//��ֹһ����û�л�ɾ
	if ((*pphead)->next == NULL)//ֻ��һ��
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//�ҵ������ڶ���
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
	assert(*pphead);//��ֹһ����û�л�ɾ

	SLNode* first = (*pphead)->next;//һ���Ͷ��������
	free(*pphead);
	*pphead = first;
}

SLNode* SLFind(SLNode* phead, int n)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur != NULL)//��while(cur)ͬ����Ч��
	{
		if (cur->data == n)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SLInsert(SLNode** pphead, SLNode* pos, int n)//��posǰ�����
{
	assert(pphead);
	assert(pos);
	SLNode* cur = *pphead;
	if (*pphead == pos)//�ڵ�һ���ڵ�ǰ�����
	{
		// ͷ��
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
	assert(*pphead != pos);//��ֹǰ��û��
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



