#define _CRT_SECURE_NO_WARNINGS 1
����˼·�� ����һ�㳣�õķ��������֣���ָ�뷭ת����ͷ�巨
1. ��ָ�뷭ת��
��¼�����������ڵ㣬ԭ���޸Ľڵ�ָ��
2. ͷ�巨
ÿһ���ڵ㶼����ͷ��
* /
// ����ָ�뷭ת��˼���������
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* n1, * n2, * n3;
    n1 = head;
    n2 = n1->next;
    n3 = n2->next;
    n1->next = NULL;
    //�м�ڵ㲻Ϊ�գ������޸�ָ��
    while (n2)
    {
        //�м�ڵ�ָ��ת
        n2->next = n1;
        //�������������Ľڵ�
        n1 = n2;
        n2 = n3;
        if (n3)
            n3 = n3->next;
    }
    //�����µ�ͷ
    return n1;
}

// ȡ�ڵ�ͷ���˼���������
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* next = cur->next;
        //ͷ���½ڵ㣬����ͷ
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }

    return newhead;