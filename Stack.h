#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	int* a;
	int top;		// ��ʶջ��λ�õ�
	int capacity;
}ST;

void STInit(ST* ps);//��ʼ��
void STDestroy(ST* ps);//����

void STPush(ST* ps, STDataType x);// ջ������
void STPop(ST* ps);// ջ��ɾ��

STDataType STTop(ST* ps);//����ջ��Ԫ��

bool STEmpty(ST* ps);//�ж�ջ�Ƿ�Ϊ��

int STSize(ST* ps);//ջ��Ԫ������