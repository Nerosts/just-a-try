#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//不允许创建临时变量，交换两个整数的内容
//int main()
//{
//	int a = 10;
//	int b = 5;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//	return 0;
//}
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//int main()
//{
//	int a = 10;
//	printf("偶数位：");
//	for (int i = 0; i < 32; i += 2)
//	{
//		printf("%d ", (a >> i) & 1);
//		
//	}
//	printf("\n");
//	printf("奇数位：");
//	for (int i = 1; i <= 31; i += 2)
//	{
//		printf("%d ", (a >> i) & 1);
//		
//	}
//	return 0;
//}

//KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。
//输入描述：
//多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。
//输出描述：
//针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) {
//        if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
//        {
//            printf("%d\n", 31);
//        }
//        else if (b == 2) {
//            if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
//            {
//                printf("%d\n", 29);
//            }
//            else {
//                printf("%d\n", 28);
//            }
//        }
//        else {
//            printf("%d\n", 30);
//        }
//    }
//
//    return 0;
//}

//变种水仙花数 - Lily Number：把任意的数字，从中间拆分成两个数字，比如1461 可以拆分成（1和461）, （14和61）, （146和1), 如果所有拆分后的乘积之和等于自身，则是一个Lily Number。
//
//例如：
//
//655 = 6 * 55 + 65 * 5
//
//1461 = 1 * 461 + 14 * 61 + 146 * 1
//
//求出 5位数中的所有 Lily Number。
//
//输入描述：
//无
//输出描述：
//一行，5位数中的所有 Lily Number，每两个数之间间隔一个空格。
//int main() {
//    for (int i = 10000; i <= 99999; i++)
//    {
//        int a1 = (i % 10) * (i / 10);
//        int a2 = (i % 100) * (i / 100);
//        int a3 = (i % 1000) * (i / 1000);
//        int a4 = (i % 10000) * (i / 10000);
//        if (a1 + a2 + a3 + a4 == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
//void changeValue(int ptr) {
//    ptr = 10;
//    printf("Inside function: %d\n", ptr);
//}
//
//int main() {
//    int x = 5;
//    printf("Before function call: %d\n", x);
//
//    changeValue(x);
//
//    printf("After function call: %d\n", x);
//
//    return 0;
//}
//
//void changeValue(int* ptr) {
//    *ptr = 10;
//    printf("Inside function: %d\n", *ptr);
//}
//
//int main() {
//    int x = 5;
//    printf("Before function call: %d\n", x);
//
//    changeValue(&x);
//
//    printf("After function call: %d\n", x);
//
//    return 0;
//}
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	return 0;
}