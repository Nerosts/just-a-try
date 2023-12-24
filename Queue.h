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
	int size; //元素数量（空间换时间）
}Queue;

void QInit(Queue* q);//初始化
void QDestroy(Queue* q);//销毁

void QPush(Queue* q, QDataType x);//插入
void QPop(Queue* q);//删除

QDataType QBack(Queue* q);//返回最后一个节点数据
QDataType QFront(Queue* q);//返回第一个节点数据

bool QEmpty(Queue* q);//是否为空

int QSize(Queue* q);//元素数量