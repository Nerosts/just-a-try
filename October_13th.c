#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	int* pa = (int*)malloc(10 * sizeof(int));
//	if (pa == NULL)
//	{
//		perror("malloc”÷¥Ì¿≤");
//		return 1;
//	}
//
//
//	return 0;
//}

void GetMemory(char** p)
{
	*p = (char*)malloc(100);
}
void Test(void)
{
	char* str = NULL;
	GetMemory(&str);
	
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;
}

int main()
{
	Test();
	return 0;
}