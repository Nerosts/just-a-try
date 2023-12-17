#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;
	int size;//the number of valid data
	int capacity;//the size of volumetric space
}SL;

void SLInit(SL* ps); //初始化
void SLDestroy(SL* ps);//销毁
void SLPrint(SL* ps);//打印

void SLPushBack(SL* ps, SLDataType x);//尾插
void SLPushFront(SL* ps, SLDataType x);//头插
void SLPopFront(SL* ps);//头删
void SLPopBack(SL* ps);//尾删

// 顺序表查找
int SLFind(SL* ps, SLDataType x);//返回下标索引
// 顺序表在pos位置插入x
void SeqListInsert(SL* ps, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* ps, int pos);







