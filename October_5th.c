#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//struct s1
//{
//	int data[1000];
//	int num;
//};
//
//void print1(struct s1 a)
//{
//	printf("%d %d %d ", a.data[0], a.data[0], a.data[0]);
//}
//
//void print2(struct s1* pa)
//{
//	printf("%d %d %d ", pa->data[0], pa->data[0], pa->data[0]);
//}
//int main()
//{
//	struct s1 a= { {1,2,4},100 };
//	print1(a);
//	print2(&a)
//	return 0;
//}

//struct s
//{
//	int a : 3;
//	int b : 4;
//	int c : 5;
//	int d : 4;
//
//};
//
//int main()
//{
//	struct s a = { 0 };
//	a.a = 10;
//	a.b = 12;
//	a.c = 3;
//	a.d = 4;
//	printf("%d", sizeof(a));
//	return 0;
//}

//enum sex
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//
//enum color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//
//int main()
//{
//	printf("%d\n", MALE);
//	printf("%d\n", FEMALE);
//	printf("%d\n", SECRET);
//	return 0;
//}

union a
{
	int a;
	char c;
};

int main()
{
	return 0;
}