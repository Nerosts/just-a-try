#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//2. 根据下式求s的值，其中n由键盘输入。
//说明：(1)要求使用循环实现；(2)输出结果保留5位小数，形式为：
//s = 1234.56789

//int main()
//{
//	int i,t1,t2,n;
//	double s;
//	scanf("%d", &n);
//	s = 0.0;
//	t1 = 1;
//	t2 = 1;
//	for (i = 2; i <= n; n++)
//	{
//		s = s + t1 * 1.0 / t2;
//		t1 = t1 + i;
//		t2 = t2 * i;
//	}
//	printf("%lf", s);
//}
int main()
{
	char ch;
	double a, b, c;
	scanf("%lf%lf", &a, &b);
	scanf("%c", &ch);
	switch (ch)
	{
	case '+':c = a + b;
		break;
	case '-':c = a - b;
		break;
	case '*':c = a * b;
		break;
	case '/':c = a / b;
		break;
	}
	printf("%lf", a);
	return 0;
}