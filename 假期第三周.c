#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char* arr[] = { "zynb","xgnb","bpnb" };
//	char* ch = "abcd";
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	printf("%s", ch);
//	return 0;
//}

//int main()
//{
//	int arr1[] = { 1,3 };
//	int(*pa)[2] = &arr1;
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,4,5,6 };
//	int* pa = arr;
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", pa[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", *(pa+i));
//	}
//	return 0;
//}

//int* printNumbers(int n, int* returnSize) {
//    // int k = pow(10, n);
//    // int i;
//    // for (i = 1; i < k; i++)
//    //     a[i - 1] = i;
//
//    // *returnSize=--i;
//    // return a;
//    int len = pow(10, n) - 1;
//    *returnSize = len;
//    int* pa = (int*)malloc(len * sizeof(int));
//    for (int i = 0; i < len; i++)
//    {
//        pa[i] = i + 1;
//    }
//    return pa;
//}
//根据输入的日期，计算是这一年的第几天。
//保证年份为4位数且日期合法。
//进阶：时间复杂度：
//?
//(
//	?
//)
//
//O(n) ，空间复杂度：
//?
//(
//	1
//)
//
//O(1)
//输入描述：
//输入一行，每行空格分割，分别是年，月，日
//
//输出描述：
//输出是这一年的第几天
//int main() {
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    int days = 0;
//    switch (b - 1) {
//    case 12:
//    case 11:days += 30;
//    case 10:days += 31;
//    case 9:days += 30;
//    case 8:days += 31;
//    case 7:days += 31;
//    case 6:days += 30;
//    case 5:days += 31;
//    case 4:days += 30;
//    case 3:days += 31;
//    case 2:if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
//    {
//        days += 29;
//    }
//          else {
//        days += 28;
//    }
//    case 1:days += 31;
//    }
//    days += c;
//    printf("%d", days);
//
//    return 0;
//}