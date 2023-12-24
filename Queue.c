#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QInit(Queue* q)
{
	assert(q);
	q->phead = q->ptail = NULL;
	q->size = 0;
}

void QDestroy(Queue* q)
{
	QNode* cur = q->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->phead = q->ptail = NULL;
	q->size = 0;
}

void QPush(Queue* q, QDataType x)
{
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);//防止没有开辟成功(当人有点杞人忧天了）
	newnode->val = x;
	newnode->next = NULL;

	if (q->phead == NULL)
	{
		q->phead = q->ptail = newnode;
	}
	else
	{
		q->ptail->next = newnode;
		q->ptail = newnode;
	}
	q->size++;
}

void QPop(Queue* q)
{
	assert(q);
	assert(q->size > 0);
	QNode* next = q->phead->next;
	free(q->phead);
	q->phead = next;
	//当只有一个节点时：把	q->ptail = NULL;
	if (q->phead == NULL)
	{
		q->ptail = NULL;
	}
	q->size--;
}

QDataType QBack(Queue* q)
{
	assert(q);
	assert(q->ptail);
	return q->ptail->val;
}

QDataType QFront(Queue* q)
{
	assert(q);
	assert(q->ptail);
	return q->phead->val;
}

bool QEmpty(Queue* q)
{
	assert(q);
	return q->size == 0;
}

int QSize(Queue* q)
{
	assert(q);
	return q->size;
}