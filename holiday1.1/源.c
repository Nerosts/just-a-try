#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n') {
//		printf("%c", ch);
//	}
//	return 0;
//}
typedef unsigned int uint;
//int main()
//{
//	uint a = 10;
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	//当我在其他文件里定义了的变量想在这个文件里直接用是不行的
//	//只能用extern函数进行声明后才行
//	 int a;
//	 while ((scanf("%d", &a) != EOF)) {
//		 printf("%d", a);
//	}
//	return 0;
//}


//小乐乐获得4个最大数，请帮他编程找到最大的数。
//输入描述：
//一行，4个整数，用空格分开。
//输出描述：
//一行，一个整数，为输入的4个整数中最大的整数。
//int main() {
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    int max = a;
//    if (b > max) {
//        max = b;
//    }
//    if (c > max) {
//        max = c;
//    }
//    if (d > max) {
//        max = d;
//    }
//    printf("%d", max);
//    return 0;
//}


//KiKi想完成字母大小写转换，有一个字符，判断它是否为大写字母，如果是，将它转换成小写字母；反之则转换为大写字母。
//输入描述：
//多组输入，每一行输入一个字母。
//输出描述：
//针对每组输入，输出单独占一行，输出字母的对应形式。
//int main() {
//    int a, b;
//    char c;
//    while (scanf("%c", &c) != EOF) {
//        if (c >= 'a' && c <= 'z') {
//            printf("%c\n", c - 32);
//        }
//        if (c >= 'A' && c <= 'Z') {
//            printf("%c\n", c + 32);
//        }
//
//
//    }
//    return 0;
//}
//KiKi想判断输入的字符是不是字母，请帮他编程实现。
//
//输入描述：
//多组输入，每一行输入一个字符。
//输出描述：
//针对每组输入，输出单独占一行，判断输入字符是否为字母，输出内容详见输出样例。
int main() {
    int a, b;
    char c;
    while (scanf("%c", &c) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%c is an alphabet.\n", c);
        }
        else {
            printf("%c is not an alphabet.\n", c);
        }
       //getchar();
    }
    return 0;
}