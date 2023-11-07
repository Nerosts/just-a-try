#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 // struct ListNode* removeElements(struct ListNode* head, int val) {
 //     struct ListNode* pre=NULL;
 //     struct ListNode* cur=head;
 //     while(cur)
 //     {
 //         if(cur->val==val)
 //         {
 //             struct ListNode* next=cur->next;
 //             free(cur);
 //             cur=next;
 //             if(pre)
 //             {
 //                 pre->next=next;
 //             }
 //             else 
 //             {
 //                 head=cur;
 //             }
 //         }
 //         else 
 //         {
 //             pre=cur;
 //             cur=cur->next;
 //         }
 //     }
 //     return head;
 // }
 // struct ListNode* removeElements(struct ListNode* head, int val) {
 //     struct ListNode* cur=head,*tail=NULL;
 //     struct ListNode* newhead=NULL;
 //     while(cur)
 //     {
 //         if(cur->val!=val)
 //         {
 //             if(newhead==NULL)
 //             {
 //                 tail=cur; 
 //                 newhead=cur;
 //             }
 //             else 
 //             {
 //                 tail->next=cur;
 //                 tail=tail->next;
 //             }
 //             cur=cur->next;
 //         }
 //         else
 //         {
 //             struct ListNode* t=cur;
 //             cur=cur->next;
 //             free(t);
 //             t=NULL;
 //         }
 //     }//5的next是野指针
 //     if(tail)
 //     {
 //         tail->next=NULL;
 //     }
 //     return newhead;
 // }

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head, * tail = NULL;
    struct ListNode* newhead = NULL;
    newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail = newhead;
    while (cur)
    {
        if (cur->val != val)
        {
            tail->next = cur;
            cur = cur->next;
            tail = tail->next;
        }
        else
        {
            struct ListNode* t = cur;
            cur = cur->next;
            free(t);
            t = NULL;
        }
    }//5的next是野指针

    tail->next = NULL;
    struct ListNode* t = newhead;
    newhead = newhead->next;
    free(t);
    return newhead;
}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* head1, * head2, * tail1, * tail2;
        head1 = tail1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        head2 = tail2 = (struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                tail1->next = cur;
                tail1 = tail1->next;

            }
            else
            {
                tail2->next = cur;
                tail2 = tail2->next;

            }
            cur = cur->next;
        }
        tail1->next = head2->next;
        tail2->next = NULL;
        return head1->next;
    }
};