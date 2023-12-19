#define _CRT_SECURE_NO_WARNINGS 1
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

}




