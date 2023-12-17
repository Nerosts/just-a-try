#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void test1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	printf("尾插三个：");
	SLPrint(&s);

	SLPushFront(&s, 0);
	SLPushFront(&s, 0);
	printf("头插2个：");
	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	printf("头删2个：");
	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	printf("尾删2个：");
	SLPrint(&s);

	SLDestroy(&s);
}

int main()
{
	test1();
	return 0;
}