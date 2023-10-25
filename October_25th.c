#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


struct S
{
	char a;
	int b;
	char c;
};

#define OFFSETOF(s,name) (int)(&(((s*)0)->name)-((s*)0))
int main()
{
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));
	return 0;
}

struct S
{
	char a;
	int b;
	char c;
};

#define OFFSETOF(s,name) (int)(&(((s*)0)->name))
int main()
{
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));
	return 0;
}