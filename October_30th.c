#define _CRT_SECURE_NO_WARNINGS 1
#include"SquList.h"

void test()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 2);
	printf("β��������");
	SLPrint(&s1);

	SLPushFront(&s1, 3);
	printf("ͷ��1����");
	SLPrint(&s1);

	SLPopBack(&s1);
	printf("βɾ1����");
	SLPrint(&s1);

	SLPopFront(&s1);
	printf("ͷɾ1����");
	SLPrint(&s1);

	SLDestroy(&s1);
}


int main()
{
	test();
	return 0;
}