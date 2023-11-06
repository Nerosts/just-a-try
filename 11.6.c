#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
struct Node
{
	int val;
	struct Node* next;
};

int main()
{
	struct Node* a= (struct Node*)malloc(sizeof(struct Node));
	a->val = 0;
	a->next = NULL;
	struct Node** pa = &a;

	assert(pa);
	return 0;
}
