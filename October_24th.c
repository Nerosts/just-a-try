#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define offset(s,n) (int)(&(s.n)-&s)
struct S
{
	char a;
	int b;
	char c;
};
//struct S s;
//int main()
//{
//	
//	int a = offset(s, s.b);
//	printf("%d", a);
//	return 0;
//}


//#define OFFSETOF(s,name) (int)(&(((s*)0)->name))
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, a));
//	printf("%d\n", OFFSETOF(struct S, b));
//	printf("%d\n", OFFSETOF(struct S, c));
//	return 0;
//}

//#define change(num) ((num&0xaaaaaaaa)>>1)+((num&0x11111111)<<1)
//
//int main()
//{
//	int a = 10;
//	printf("%d", change(a));
//	return 0;
//}

//enum Sex
//{
//	MALE,
//	FEMALE=8,
//	SECRET
//};
//
//int main()
//{
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//	return 0;
//}

union A //定义一个共用体
{
	char a;
	int b;
};

//int main()
//{
//	union A a; //创建一个共用体变量
//	printf("%p\n", &a);
//	printf("%p\n", &(a.a));
//	printf("%p\n", &(a.b));
//	return 0;
//}\

//int judge()
//{
//	union A u;
//	u.b = 1;
//	return u.a;
//}
//
//int main()
//{
//	int a = judge();
//	if (a == 1)
//	{
//		printf("是小端");
//	}
//	else
//	{
//		printf("是大端");
//	}
//	return 0;
//}

union U1
{
	char arr[5]; //5个字节
	int a;  //4个字节
};
int main()
{
	printf("%d", sizeof(union U1));//如果只是最大的成员变量的大小，那应当输出5
	return 0;
}