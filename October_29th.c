#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* arr = (int*)malloc(sizeof(int) * 10);//使用malloc函数进行动态内存开辟
//	//因为返回值是void* 所以要强转一下
//	if (arr == NULL)
//	{
//		perror("malloc");//如果开辟失败就进行说明
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//
//	free(arr);//在程序最后要结束时主动进行释放
//
//	return 0;
//}

//int main()
//{
//	int* p = (int*)calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		perror("calloc");
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		p[i] = i;
//	}
//
////使用。。。。
//
//	int* pa = NULL;
//	pa = realloc(p, 1000);
//	if (p != NULL)
//	{
//		p = pa;
//	}
//
//	free(p);
//	p = NULL;
//	return 0;
//}

void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}