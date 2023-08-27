#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Lily上课时使用字母数字图片教小朋友们学习英语单词
//每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过代码解决。
//Lily使用的图片使用字符"A"到"Z"、"a"到"z"、"0"到"9"表示。
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int cmp(void* a, void* b)
//{
//    return *(char*)a - *(char*)b;
//}
//int main() {
//    char arr[1000];
//    gets(arr);
//    qsort(arr, strlen(arr), sizeof(char), cmp);
//    printf("%s", arr);
//    return 0;
//}

//给你一个整数数组 nums ，请计算数组的 中心下标 。
//数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
//如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
//如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 - 1
//

//第一种最简单的方法；
int pivotIndex(int* nums, int numsSize) {

    for (int i = 0; i < numsSize; i++)
    {
        int left = 0, right = 0;
        //求左侧的和
        for (int j = 0; j < i; j++)
        {
            left += nums[j];
        }
        //求右侧的和
        for (int k = i + 1; k < numsSize; k++)
        {
            right += nums[k];
        }
        if (left == right)
        {
            return i;
        }
    }
    return -1;
}

//稍微简单一点的
int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    int left = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (2 * left + nums[i] == total)
        {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
