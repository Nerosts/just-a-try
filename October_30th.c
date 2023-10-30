#define _CRT_SECURE_NO_WARNINGS 1
#include"SquList.h"

void test()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 2);
	printf("尾插两个数");
	SLPrint(&s1);

	SLPushFront(&s1, 3);
	printf("头插1个数");
	SLPrint(&s1);

	SLPopBack(&s1);
	printf("尾删1个数");
	SLPrint(&s1);

	SLPopFront(&s1);
	printf("头删1个数");
	SLPrint(&s1);

	SLDestroy(&s1);
}


int main()
{
	test();
	return 0;
}