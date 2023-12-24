#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;

}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size; //Ԫ���������ռ任ʱ�䣩
}Queue;

void QInit(Queue* q);//��ʼ��
void QDestroy(Queue* q);//����

void QPush(Queue* q, QDataType x);//����
void QPop(Queue* q);//ɾ��

QDataType QBack(Queue* q);//�������һ���ڵ�����
QDataType QFront(Queue* q);//���ص�һ���ڵ�����

bool QEmpty(Queue* q);//�Ƿ�Ϊ��

int QSize(Queue* q);//Ԫ������