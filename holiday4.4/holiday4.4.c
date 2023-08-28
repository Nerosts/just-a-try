#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10 + 2] = { 0 };
	printf("%d", arr[2]);
	return 0;
}

//编写一个函数，计算字符串中含有的不同字符的个数。
//字符在 ASCII 码范围内(0~127 ，包括 0 和 127)，换行表示结束符，不算在字符里。
//不在范围内的不作统计。多个相同的字符只计算一次
//例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void* a, void* b)
{
    return *(char*)a - *(char*)b;
}
int main() {
    char arr[500] = { '0' };
    gets(arr);
    qsort(arr, strlen(arr), sizeof(char), cmp);
    int count = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] != arr[i - 1])
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}

//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素
int cmp(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}
int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}

//自除数 是指可以被它包含的每一位数整除的数。
//例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//自除数 不允许包含 0 。
//给定两个整数 left 和 right ，返回一个列表，列表的元素是范围[left, right] 内所有的 自除数
int judge(int num)
{
    int primary = num;
    while (num > 0)
    {
        int a = num % 10;
        if (a == 0)
        {
            return 0;
        }
        else if (primary % a != 0)
        {
            return 0;
        }
        num /= 10;
    }
    return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* arr = (int*)malloc((right - left + 1) * sizeof(int));
    int j = 0;
    for (int i = left; i <= right; i++)
    {
        if (judge(i))
        {
            arr[j++] = i;
        }
    }
    *returnSize = j;
    return arr;
}