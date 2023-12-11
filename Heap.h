#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HInit(HP* php);
void HDestroy(HP* php);

void HPush(HP* php, HPDataType x);
void HeapPop(HP* php);

HPDataType HeapTop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);