#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
///*������*/�������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ������ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� - 1
//int dominantIndex(int* nums, int numsSize) {
//    //��������
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

//������������ nums1 �� nums2 ������ ���ǵĽ��� ��
//�������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳��
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