#define _CRT_SECURE_NO_WARNINGS 1
//给你单链表的头结点 head ，请你找出并返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // struct ListNode* middleNode(struct ListNode* head) {
 //     int count=1;
 //     struct ListNode* sum=head;
 //     while(sum->next!=NULL)
 //     {
 //         count++;
 //         sum=sum->next;
 //     }
 //     int a=count/2;
 //     while(a--)
 //     {
 //         head=head->next;
 //     }
 //     return head;
 // }

 // struct ListNode* middleNode(struct ListNode* head) {
 //     struct ListNode* oneStep=head;
 //     struct ListNode* twoStep=head;
 //     while(twoStep->next!=NULL)
 //     {
 //         oneStep=oneStep->next;
 //         twoStep=twoStep->next;
 //         if(twoStep->next==NULL)
 //         {
 //             break;
 //         }
 //         else
 //         {
 //             twoStep=twoStep->next;
 //         }
 //     }
 //     return oneStep;
 // }

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* oneStep = head;
    struct ListNode* twoStep = head;
    while (twoStep && twoStep->next)
    {
        oneStep = oneStep->next;
        twoStep = (twoStep->next)->next;
    }
    return oneStep;
}