#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。
//例如：
//1 ^ 3 = 1
//2 ^ 3 = 3 + 5
//3 ^ 3 = 7 + 9 + 11
//4 ^ 3 = 13 + 15 + 17 + 19
//输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
//数据范围：1≤�≤01≤m≤100
//int main() {
//    int m;
//    scanf("%d", &m);
//    int a = pow(m, 3);
//    int a1 = (int)a / m - (m - 1);
//    printf("%d", a1);
//    for (int i = 1; i < m; i++)
//    {
//        printf("+%d", a1 + 2 * i);
//    }
//    return 0;
//}

//等差数列 2，5，8，11，14。。。。
//（从 2 开始的 3 为公差的等差数列）
//输出求等差数列前n项和
//
//
//数据范围：
//1
//≤
//�
//≤
//1000
//
//1≤n≤1000
//int main() {
//    int n;
//    scanf("%d", &n);
//    int Sn = 2 * n + n * (n - 1) * 3 / 2;
//    printf("%d", Sn);
//    return 0;
//}
//首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
//0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0
//int main()
//{
//    int n, count = 0, count1 = 0;
//    float avg, sum = 0;
//    scanf("%d", &n);
//    int* buf = (int*)malloc(n * sizeof(int));
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d ", &buf[i]);
//    }
//
//    for (int i = 0; i < n; i++) {
//        if (buf[i] < 0) {
//            count++;
//        }
//        else if (buf[i] > 0) {
//            sum += buf[i];
//            count1++;
//        }
//    }
//    if (count1 == 0)
//    {
//        printf("%d %.1f", count, sum);
//    }
//    else {
//        avg = sum / count1;
//        printf("%d %.1f", count, avg);
//    }
//    return 0;
//
///*有*/一个长度
//为 n 的非降序数组，比如[1, 2, 3, 4, 5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的
//末尾，变成一个旋转数组，比如变成了[3, 4, 5, 1, 2]，或者[4, 5, 1, 2, 3]这样的。请问，给定这样一个旋
//转数组，求数组中的最小值
int minNumberInRotateArray(int* arr, int arrSize)
{
    int left = 0;
    int right = arrSize - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] < arr[right])
            right = mid;
        else if (arr[mid] > arr[right])
            left = mid + 1;
        else
            right -= 1;
    }
    return arr[left];
}