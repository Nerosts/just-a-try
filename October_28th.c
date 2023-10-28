#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//数组nums包含从0到n的所有整数，但其中缺了一个。
//请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

//int missingNumber(int* nums, int numsSize) {
//    int sum = (numsSize + 1) * (numsSize) / 2;
//    int s = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        s += nums[i];
//    }
//    return sum - s;
//}
//
//int missingNumber(int* nums, int numsSize) {
//    int a = 0;
//    int* arr = malloc(4 * (numsSize + 1));
//    for (int i = 0; i < strlen(arr); i++)
//    {
//        arr[i] = i;
//    }
//    int ret = 0;
//
//}
//
//int missingNumber(int* nums, int numsSize) {
//    int a = 0;
//
//    for (int i = 0; i <= numsSize; i++)
//    {
//        a ^= i;
//    }
//    for (int i = 0; i < numsSize; i++)
//    {
//        a ^= nums[i];
//    }
//
//    return a;
//
//}

//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
// void rotate(int* nums, int numsSize, int k){
//     int arr[numsSize];
//     for (int i = 0; i < numsSize; ++i) 
//     {
//         arr[(i + k) % numsSize] = nums[i];
//     }

//     for (int i = 0; i < numsSize; ++i) 
//     {
//            nums[i] = arr[i];
//     }


// }
void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int t = nums[left];
        nums[left] = nums[right];
        nums[right] = t;
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    if (k > numsSize) {
        k = k % numsSize;
    }
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);

}
oid rotate(int* nums, int numsSize, int k) {
    int arr[numsSize];
    int j = 0;
    k = k % numsSize;
    for (int i = numsSize - k; i < numsSize; i++)
    {
        arr[j++] = nums[i];
    }
    for (int i = 0; i < numsSize - k; i++)
    {
        arr[j++] = nums[i];
    }
    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = arr[i];
    }

}