#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};


int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));

	n1->val = 1;
	n2->val = 1;
	n3->val = 1;
	n4->val = 1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	return 0;
}
