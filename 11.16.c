/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // struct ListNode* reverseList(struct ListNode* head) {
 //     struct ListNode* n1,*n2,*n3;
 //     n1=NULL;
 //     n2=head;
 //     if(head==NULL)
 //     {
 //         return NULL;
 //     }
 //     n3=head->next;
 //     while(n2)
 //     {
 //         n2->next=n1;
 //         n1=n2;
 //         n2=n3;
 //         if(n3)
 //         n3=n3->next;
 //     }
 //     return n1;
 // }

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = NULL;
        next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}#define _CRT_SECURE_NO_WARNINGS 1