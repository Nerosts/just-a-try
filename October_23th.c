#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	printf("%s", __TIME__);
//	printf("%s", __DATE__);
//	return 0;
//}
//#define ADD(x,y) x+y
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = ADD(a, b);
//	int d = ADD(a, b) * 3;
//	printf("%d\n", c);
//	printf("%d\n", d);
//	return 0;
//}

//#define Print(n,format) printf("the value of "#n" is "#format"\n",n)
//int main()
//{
//	int a = 10;
//	Print(a, %d);
//	printf("value of ""a"" is ""%d"" ", a);
//	return 0;
//}

//#define Malloc(n,type) (type*)malloc(sizeof(type)*n)
//int main()
//{
//	int* arr = Malloc(10, int);
//
//	return 0;
//}d

#define CHANGE(a) 

//int main()
//{
//	int a = 10;
//	for (int i = 0; i < 32; i+=2)
//	{
//		int ji = (a >> i) & 1;
//		(a >> i)&1 = (a >> (i+1))&1;
//		
//	return 0;
//}

//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//#pragma pack(8)//����Ĭ�϶�����Ϊ8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
//#pragma pack(1)//����Ĭ�϶�����Ϊ1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//	printf("%d", sizeof(struct S2));
//	return 0;
//}

//struct S
//{
//	int data[1000];
//	int num;
//};
//struct S s = { {1,2,3,4}, 1000 };
////�ṹ�崫��
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//	printf("%d\n", s.data[0]);
//	printf("%d\n", s.data[1]);
//	printf("%d\n", s.data[2]);
//}
////�ṹ���ַ����
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//	printf("%d\n", ps->data[0]);
//	printf("%d\n", ps->data[1]);
//	printf("%d\n", ps->data[2]);
//}
//int main()
//{
//	print1(s); //���ṹ�����
//	printf("_________\n");
//	print2(&s); //����ַ
//	return 0;
//}
//struct A {
//	int a : 2; //aռ��2��bitλ
//	int b : 5; //bռ��5��bitλ
//	int c : 10;
//	int d : 30;
//};
//
//int main()
//{
//	struct A a;
//	printf("%d", sizeof(a));
//}

struct S1
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};

struct S2
{
	char a;
	char b;
	char c;
	char d;
};
int main()
{
	struct S1 s1 = { 0 };
	s1.a = 10;
	s1.b = 12;
	s1.c = 3;
	s1.d = 4;
	char* arr = "abc";

	struct S2 s2 = { 0 };
	s2.a = 10;
	s2.b = 12;
	s2.c = 3;
	s2.d = 4;

	return 0;
}