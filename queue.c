#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"

void QInit(Queue* q)
{
	assert(q);
	q->phead = NULL;
	q->ptail = NULL;
	q->size = 0;
}

void QDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->phead = q->ptail = NULL;
	
}

void QPush(Queue* q, QDataType x) //Î²²å
{
	assert(q);
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->next = NULL;
	newNode->val = x;
	if (q->ptail == NULL)
	{
		q->phead = q->ptail = newNode;
	}
	else
	{
		q->ptail->next = newNode;
		q->ptail = newNode;
	}
	q->size++;
}

void QPop(Queue* q)//Í·É¾
{
	assert(q);
	assert(q->phead);
	QNode* first = q->phead;
	q->phead = q->phead->next;
	free(first);
	first = NULL;
	if (q->phead == NULL)
	{
		q->ptail = NULL;
	}
	q->size--; 
}

QDataType QBack(Queue* q)
{
	assert(q);
	assert(q->phead);
	return q->ptail->val;
}

QDataType QFront(Queue* q)
{
	assert(q);
	assert(q->phead);
	return q->phead->val;
}

bool QEmpty(Queue* q)
{
	assert(q);
	return q->phead == NULL;
}

int QSize(Queue* q)
{
	return q->size;
}

