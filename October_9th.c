#define _CRT_SECURE_NO_WARNINGS 1

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// // struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
// //   struct ListNode *curA=headA;
// //    struct ListNode *curB=headB;
// //     while(curA)
// //     {
// //         while(curB)
// //         {
// //             if(curA==curB)
// //             {
// //                 return curA;
// //             }
// //             curB=curB->next;
// //         }
// //         curA=curA->next;
// //         curB=headB;
// //     }
// //     return NULL;
// // }

// // struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
// //     struct ListNode *curA=headA;
// //     struct ListNode *curB=headB;
// //     int countA=0;
// //     int countB=0;
// //     while(curA->next!=NULL)
// //     {
// //         countA++;
// //     }
// //     while(curB->next!=NULL)
// //     {
// //         countB++;
// //     }
// //     if(curA!=curB)
// //     {
// //         return NULL;
// //     }
// //     int difference=0;
// //     if(countA>countB)
// //     {
// //         difference=countA-countB;
// //         while(difference)
// //         {
// //             headA=headA->next;
// //         }
// //     }else
// //     {
// //         difference=countB-countA;
// //         while(difference)
// //         {
// //             headB=headB->next;
// //         }
// //     }
// //     while(headA!=headB)
// //     {
// //         headA=headA->next;
// //         headB=headB->next;
// //     }
// //     return headA;
// // }

// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//     struct ListNode *curA=headA;
//     struct ListNode *curB=headB;
//     int countA=0;
//     int countB=0;
//     while(curA->next!=NULL)
//     {
//         countA++;
//         curA=curA->next;
//     }
//     while(curB->next!=NULL)
//     {
//         countB++;
//         curB=curB->next;
//     }
//     if(curA!=curB)
//     {
//         return NULL;
//     }
//     int difference=abs(countA-countB);
//     struct ListNode *Long=headA;
//     struct ListNode *Short=headB;
//     if(countA<countB)
//     {
//           struct ListNode *Long=headB;
//     struct ListNode *Short=headA;
//     }
//     while(difference--)
//     {
//         Long=Long->next;
//     }
//     while(Long!=Short)
//     {
//         if(Long)
//         Long=Long->next;
//         Short=Short->next;
//     }
//     return Short;
// }