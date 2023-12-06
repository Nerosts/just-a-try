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
	printf("尾插3个  ");
	LTPrint(plist);

	LTPopBack(plist);
	printf("尾删1个  ");
	LTPrint(plist);

	LTPushFront(plist, 9);
	printf("头插1个  ");
	LTPrint(plist);

	LTPopFront(plist);
	printf("头删1个  ");
	LTPrint(plist);

	LTNode* find=LTFind(plist, 2);
	ListInsert(find, 11);
	LTPrint(plist);
	return 0;
}