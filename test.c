#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void test1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	printf("β��������");
	SLPrint(&s);

	SLPushFront(&s, 0);
	SLPushFront(&s, 0);
	printf("ͷ��2����");
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	printf("ͷɾ2����");
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	printf("βɾ2����");
	SLPrint(&s);

	SLDestroy(&s);
}

int main()
{
	test1();
	return 0;
}