#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 1 };
	return 0;
}
//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//请不要使用除法，且在 O(n) 时间复杂度内完成此题
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
//写一个函数，求两个整数之和，要求在函数体内不得使用 + 、 - 、 * 、 / 四则运算符号。
//数据范围：两个数都满足
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