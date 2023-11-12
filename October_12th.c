#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    // if(cur==NULL)
    // {
    //     return NULL;
    // }
    while (cur)
    {
        struct Node* copied = (struct Node*)malloc(sizeof(struct Node));
        copied->val = cur->val;

        // struct Node* next=cur->next;
        // cur->next=copied;
        // copied->next=next;
        // cur=next;
        copied->next = cur->next;
        cur->next = copied;
        cur = cur->next->next;
    }

    struct Node* ran = head;//随机节点的copy
    while (ran)
    {
        struct Node* copy = ran->next;
        if (ran->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = ran->random->next;
        }
        ran = ran->next->next;
    }

    // struct Node* newhead=NULL;//start to connect all the copied Nodes
    // struct Node* tail=NULL;
    // struct Node* link=head;
    // while(link&&link->next)
    // {
    //     if(tail=NULL)
    //     {
    //         newhead=tail=link->next;
    //         link=link->next;
    //     }
    //     else 
    //     {
    //     tail->next=link->next;
    //     tail=tail->next;

    //     }
    //     link=link->next;
    // }
    // return newhead;
    struct Node* newhead = NULL;  //start to connect all the copied Nodes
    struct Node* tail = NULL;
    struct Node* link = head;
    while (link)
    {
        struct Node* copy = link->next;
        struct Node* next = copy->next;
        if (tail == NULL)
        {
            newhead = tail = link->next;

        }
        else
        {
            tail->next = copy;
            tail = tail->next;
        }
        link->next = next;
        link = next;
    }
    return newhead;
}