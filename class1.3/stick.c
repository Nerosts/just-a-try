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
//	k = a / b;//�����о�Ϊ��ʽ���ʽ
//
//	return 0;
//}
//int main()
//{
//	int a = 1; 
//	int b = 2;
//	int c = 3;
//	int d = 4;// ������Щ��ϵ���ʽ�Ľ��Ϊ:
//
//	//a + b > c - d  ��� : 1
//    //a > 3 / 2  ���:0
//    //'a' + 1 < 'c' ��� : 1  �ַ���������ʱ���Ƚϵ�����ASCII���ֵ*/
//    //a + 1 == b  ��� : 1
//    //a > b > > C  ��� : 0  �ȼ���a>b�Ľ��Ϊ0,�ټ���0>c�Ľ��Ϊ0*/
//	return 0;
//}
//int main()
//{
//	int a,b,c;
//	
//	//a < b&& c;
//	//a==b||c;   ��Ϊ�߼����ʽ
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