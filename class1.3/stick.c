#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 1;
//
//	int i, j, k;
//	i = a + b;
//	j = a % 2 / 1;
//	k = a / b;//这四行均为算式表达式
//
//	return 0;
//}
//int main()
//{
//	int a = 1; 
//	int b = 2;
//	int c = 3;
//	int d = 4;// 下面这些关系表达式的结果为:
//
//	//a + b > c - d  结果 : 1
//    //a > 3 / 2  结果:0
//    //'a' + 1 < 'c' 结果 : 1  字符参与运算时，比较的是其ASCII码的值*/
//    //a + 1 == b  结果 : 1
//    //a > b > > C  结果 : 0  先计算a>b的结果为0,再计算0>c的结果为0*/
//	return 0;
//}
//int main()
//{
//	int a,b,c;
//	
//	//a < b&& c;
//	//a==b||c;   均为逻辑表达式
//	return 0;
//}
int main()
{
	int a = 1;
	int b = 3;
	int c = a > b ? a : b;
	printf("%d", c);
	return 0;
}