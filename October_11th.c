#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {//无哨兵位
 //     struct ListNode* newhead=NULL;
 //     struct ListNode* tail=NULL;
 //     struct ListNode* cur1=list1;
 //     struct ListNode* cur2=list2;
 //     if(list1==NULL)
 //     {
 //         return list2;
 //     }
 //     if(list2==NULL)
 //     {
 //         return list1;
 //     }
 //     while(cur1&&cur2)
 //     {
 //         if(cur1->val<=cur2->val)
 //         {
 //             if(tail==NULL)
 //             {
 //                 newhead=tail=cur1;
 //             }
 //             else
 //             {
 //                 tail->next=cur1; 
 //                 tail=tail->next;
 //             }

 //             cur1=cur1->next;
 //         }
 //         else
 //         {
 //             if(tail==NULL)
 //             {
 //                 newhead=tail=cur2;
 //             }
 //             else
 //             {
 //                 tail->next=cur2;
 //                 tail=tail->next;
 //             }

 //             cur2=cur2->next;
 //         }
 //     }
 //     if(cur1==NULL)
 //     {
 //         tail->next=cur2;
 //     }
 //     if(cur2==NULL)
 //     {
 //         tail->next=cur1;
 //     }
 //     return newhead;
 // }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {//有哨兵位
    struct ListNode* newhead, * tail;
    newhead = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur1 = list1;
    struct ListNode* cur2 = list2;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    while (cur1 && cur2)
    {
        if (cur1->val <= cur2->val)
        {
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            tail = tail->next;
            cur2 = cur2->next;
        }
    }
    if (cur1 == NULL)
    {
        tail->next = cur2;
    }
    if (cur2 == NULL)
    {
        tail->next = cur1;
    }
    return newhead->next;
}