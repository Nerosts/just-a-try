#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1 };
	return 0;
}
//����һ���������� nums������ ���� answer ������ answer[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻� ��
//��Ŀ���� ��֤ ���� nums֮������Ԫ�ص�ȫ��ǰ׺Ԫ�غͺ�׺�ĳ˻�����  32 λ ������Χ�ڡ�
//�벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ���
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(numsSize * sizeof(int));
    int L[numsSize];
    int R[numsSize];
    L[0] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        L[i] = L[i - 1] * nums[i - 1];
    }
    R[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--)
    {
        R[i] = R[i + 1] * nums[i + 1];
    }
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        answer[i] = L[i] * R[i];
    }
    return answer;
}
//
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�� + �� - �� * �� / ����������š�
//���ݷ�Χ��������������
int Add(int num1, int num2) {
    // write code here
    int result = 0;
    while (num1)
    {
        int a = num1 ^ num2;
        num1 = (num1 & num2) << 1;
        num2 = a;
    }

    return num2;
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int x = 0;
    int* arr = (int*)malloc(2 * numsSize * sizeof(int));
    int* arr1 = (int*)malloc(2 * numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        arr[nums[i]] = 1;
    }
    *returnSize = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        if (arr[i] != 1)
        {
            arr1[(*returnSize)++] = i;
        }
    }
    return arr1;
}            