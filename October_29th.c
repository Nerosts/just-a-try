#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* arr = (int*)malloc(sizeof(int) * 10);//ʹ��malloc�������ж�̬�ڴ濪��
//	//��Ϊ����ֵ��void* ����Ҫǿתһ��
//	if (arr == NULL)
//	{
//		perror("malloc");//�������ʧ�ܾͽ���˵��
//	}
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//
//	free(arr);//�ڳ������Ҫ����ʱ���������ͷ�
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
////ʹ�á�������
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