#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
///*请你找*/出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 - 1
//int dominantIndex(int* nums, int numsSize) {
//    //先找最大的
//    int max = nums[0];
//    int dex = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//        {
//            max = nums[i];
//            dex = i;
//        }
//    }
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        if (dex == i)
//        {
//            continue;
//        }
//        if (nums[i] * 2 > max)
//        {
//            return -1;
//        }
//    }
//    return dex;
//}

//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。
//输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int* intersection = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int index1 = 0;
    int index2 = 0;
    *returnSize = 0;
    while (index1 < nums1Size && index2 < nums2Size)
    {
        int num1 = nums1[index1];
        int num2 = nums2[index2];
        if (num1 == num2)
        {
            if (*returnSize == 0 || nums1[index1] != intersection[(*returnSize) - 1])
            {
                intersection[*returnSize] = nums1[index1];
                (*returnSize)++;
            }
            index1++;
            index2++;
        }
        else if (num1 < num2)
        {
            index1++;
        }
        else
        {
            index2++;
        }
    }
    return intersection;
}