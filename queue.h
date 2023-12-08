#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QNode
{
	QDataType val;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size; //¿Õ¼ä»»Ê±¼ä
}Queue;

void QInit(Queue* q);
void QDestroy(Queue* q);

void QPush(Queue* q, QDataType x);
void QPop(Queue* q);

QDataType QBack(Queue* q);
QDataType QFront(Queue* q);

bool QEmpty(Queue* q);
int QSize(Queue* q);
