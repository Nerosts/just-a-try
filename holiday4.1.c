#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//小明同学最近开发了一个网站，在用户注册账户的时候，需要设置账户的密码，为了加强账户的安全性，小明对密码强度有一定要求：
//1. 密码只能由大写字母，小写字母，数字构成；
//2. 密码不能以数字开头；
//3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；
//4. 密码长度至少为8
//现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的
int main() {
    int n;

    scanf("%d", &n);
    while (n--)
    {
        int small = 0, big = 0, num = 0, other = 0;
        char password[101];
        scanf("%s", password);
        if (strlen(password) < 8)
        {
            printf("NO\n");

            continue;
        }
        if (password[0] >= '0' && password[0] < '9')
        {
            printf("NO\n");

            continue;
        }
        for (int i = 0; i < strlen(password); i++)
        {
            if (password[i] >= '0' && password[i] < '9')
            {
                num++;
            }
            else if (password[i] >= 'A' && password[i] < 'Z')
            {
                big++;
            }
            else if (password[i] >= 'a' && password[i] < 'z')
            {
                small++;
            }
            else
            {
                other++;
            }
        }
        if (other != 0)
        {
            printf("NO\n");

            continue;
        }
        if ((small > 0) + (big > 0) + (num > 0) < 2)
        {
            printf("NO\n");

            continue;
        }
        printf("YES\n");
    }
    return 0;
}
//给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数
//最为简单的
int GetNumberOfK(int* nums, int numsLen, int k) {
    // write code here
    int count = 0;
    for (int i = 0; i < numsLen; i++)
    {
        if (k == nums[i])
        {
            count++;
        }
    }
    return count;
}

//用二分查找来do it
*@param nums int整型一维数组
* @param numsLen int nums数组长度
* @param k int整型
* @return int整型
* /
int GetNumberOfK(int* nums, int numsLen, int k) {
    // write code here
    if (numsLen == 0)
    {
        return 0;
    }
    else if (k > nums[numsLen - 1] || k < nums[0])
    {
        return 0;
    }
    else {
        int left = 0;
        int right = numsLen - 1;
        int leftbound = 0;
        int rightbound = 0;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        leftbound = left;

        left = 0;
        right = numsLen - 1;
        while (left < right) {
            mid = (left + right) / 2 + 1;
            if (nums[mid] > k) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        rightbound = right;
        return rightbound - leftbound + 1;
    }
}
//整数转换。编写一个函数，确定需要改变几个位才能将整数A转成整数B
int convertInteger(int A, int B) {
    int difference = A ^ B;
    int count = 0;
    for (int i = 0; i <= 31; i++)
    {
        if ((difference >> i) & 1 == 1)
        {
            count++;
        }
    }
    return count;
}