#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//2. ������ʽ��s��ֵ������n�ɼ������롣
//˵����(1)Ҫ��ʹ��ѭ��ʵ�֣�(2)����������5λС������ʽΪ��
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