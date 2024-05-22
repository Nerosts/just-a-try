#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>

// �������A��B��������������ι鲢��һ�������
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

// ˳���洢�Ķ�·�鲢�㷨
void mergeSort(std::vector<int>& A, int low, int high) 
{
    if (low < high) 
    {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);      // ����˼�룬�ݹ�ض����������������
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);    // ���ź�������������ֹ鲢
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

// ���嵥����ڵ�
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ����������A��B��������������ι鲢��һ�������
ListNode* merge(ListNode* head1, ListNode* head2) 
{
    ListNode* dummy = new ListNode(-1); // �����ƽ����߼�
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

// ������洢�Ķ�·�鲢�㷨
ListNode* mergeSortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr) 
    {
        return head;
    }
    // ����ָ���ҵ��е�
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2 = slow->next;
    slow->next = nullptr; // �Ͽ�����
    head = mergeSortList(head); // ����벿������
    head2 = mergeSortList(head2); // ���Ұ벿������
    return merge(head, head2); // �ϲ�
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