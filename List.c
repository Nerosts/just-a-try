#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

int main()
{
	//LTNode* plist = LTInit();
	LTNode* plist = NULL;
	MYLTInit(&plist);

	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	printf("β��3��  ");
	LTPrint(plist);

	LTPopBack(plist);
	printf("βɾ1��  ");
	LTPrint(plist);

	LTPushFront(plist, 9);
	printf("ͷ��1��  ");
	LTPrint(plist);

	LTPopFront(plist);
	printf("ͷɾ1��  ");
	LTPrint(plist);

	LTNode* find=LTFind(plist, 2);
	ListInsert(find, 11);
	LTPrint(plist);
	return 0;
}