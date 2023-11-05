#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void ToMalloc(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void test1(void)
//{
//	char* str = NULL; 
//	ToMalloc(&str);
//	strcpy(str, "hello");
//	printf(str);//就是printf("%s",str);
//}

//char* ToMalloc(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void test2(void)
//{
//	char* str = NULL;
//	str = ToMalloc();
//	printf(str);
//}

//void ToMalloc(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void test3(void)
//{
//	char* str = NULL;
//	ToMalloc(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}

//void test4()
//{
//	char* str = (char*)malloc(100);
//	strcpy(str, "hello");
//	free(str);
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//}

struct s
{
	char a;
	int b;
	int c[0];//柔性数组成员
};

//int main()
//{
//	struct s* s1 = (struct s*)malloc(sizeof(struct s)+20);
//	if (s1 == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	//赋值
//	s1->a = 'a';
//	s1->b = 6;
//	for (int i = 0; i < 5; i++)
//	{
//		s1->c[i] = i;
//	}
//	//打印
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ",s1->c[i]);
//	}
//
//	//如果不够，就扩容
//	struct s* s2 = (struct s*)realloc(s1, sizeof(struct s) + 40);
//	if (s1 != NULL)
//	{
//		s1 = s2;
//	}
//	else
//	{
//		return 1;
//	}
//	//释放
//	free(s1);
//	s1 = NULL;
//	return 0;
//}

struct S
{
	char a;
	int b;
	int* c;
};

int main()
{
	printf("%d", sizeof(struct S));
	struct S* s1 = (struct s*)malloc(sizeof(struct s));
	if (s1 == NULL)
	{
		perror("malloc");
		return 1;
	}
	//赋值
	s1->a = 'a';
	s1->b = 6;
	s1->c = (int*)malloc(20);
	for (int i = 0; i < 5; i++)
	{
		s1->c[i] = i;
	}
	//打印
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", s1->c[i]);
	}

	//如果不够，就扩容
	int p = (struct s*)realloc(s1->c,40);
	if (s1 != NULL)
	{
		s1->c = p; 
	}
	else
	{
		return 1;
	}
	//释放
	free(s1->c);
	s1->c = NULL;
	free(s1);
	s1 = NULL;
	return 0;
}