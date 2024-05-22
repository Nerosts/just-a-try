#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>

// 将有序表A和B的两个相邻有序段归并成一个有序段
void merge(std::vector<int>& A, int low, int mid, int high) 
{
    std::vector<int> temp(high - low + 1);
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) 
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }
    while (i <= mid) temp[k++] = A[i++];
    while (j <= high) temp[k++] = A[j++];
    for (i = 0; i < k; ++i)
        A[low + i] = temp[i];
}

// 顺序表存储的二路归并算法
void mergeSort(std::vector<int>& A, int low, int high) 
{
    if (low < high) 
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);      // 分治思想，递归地对左右两半进行排序
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);    // 将排好序的左右两部分归并
    }
}

int main() 
{
    std::vector<int> myArray = { 38, 27, 43, 3, 9, 82, 10 };
    mergeSort(myArray, 0, myArray.size() - 1);
    for (auto a : myArray) 
    {
        std::cout << a << " ";
    }
    return 0;
}

#include <iostream>

// 定义单链表节点
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 将有序链表A和B的两个相邻有序段归并成一个有序段
ListNode* merge(ListNode* head1, ListNode* head2) 
{
    ListNode* dummy = new ListNode(-1); // 设置哑结点简化逻辑
    ListNode* tail = dummy;
    while (head1 != nullptr && head2 != nullptr) 
    {
        if (head1->val < head2->val) 
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else 
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != nullptr)
        tail->next = head1;
    if (head2 != nullptr)
        tail->next = head2;
    return dummy->next;
}

// 单链表存储的二路归并算法
ListNode* mergeSortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return head;
    }
    // 快慢指针找到中点
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = nullptr; // 断开链表
    head = mergeSortList(head); // 对左半部分排序
    head2 = mergeSortList(head2); // 对右半部分排序
    return merge(head, head2); // 合并
}

int main() 
{
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(1);
    head = mergeSortList(head);
    ListNode* curr = head;
    while (curr != nullptr) 
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}