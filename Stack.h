#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	int* a;
	int top;		// 标识栈顶位置的
	int capacity;
}ST;

void STInit(ST* ps);//初始化
void STDestroy(ST* ps);//销毁

void STPush(ST* ps, STDataType x);// 栈顶插入
void STPop(ST* ps);// 栈顶删除

STDataType STTop(ST* ps);//返回栈顶元素

bool STEmpty(ST* ps);//判断栈是否为空

int STSize(ST* ps);//栈中元素数量