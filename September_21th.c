#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char a = 'z';
//	char* pa = &a;
//	return 0;
//}

//int main()
//{
//	char* arr = "hello";
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "hello";
//	const char* str3 = "hello";
//	const char* str4 = "hello";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}

//int main()
//{
//	int arr1[4] = { 1,2,4,5 };
//	int arr2[4] = { 2,2,5,5 };
//	int arr3[4] = { 1,1,4,4 };
//
//	int* pa[3] = { &arr1,&arr2,&arr3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("%d ", pa[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "abc";
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//
//	return 0;
//}

//void print_arr(int(*arr)[5], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	//������arr����ʾ��Ԫ�صĵ�ַ
//	//���Ƕ�ά�������Ԫ���Ƕ�ά����ĵ�һ��
//	//�������ﴫ�ݵ�arr����ʵ�൱�ڵ�һ�еĵ�ַ����һά����(�����Ԫ��)�ĵ�ַ
//	//��������ָ��������
//	print_arr(arr, 3, 5);
//	return 0;
//}

//void test(int arr[])//����    ���鴫�Σ��β��ǿ���д��������ʽ��
//{}
//void test(int arr[10])//����
//{}
//void test(int* arr)//����     ���鴫�εı����Ǵ�����������Ԫ�صĵ�ַ���β�Ҳ������ָ��
//{}
//void test2(int* arr[20])//���� 
//{}
//void test2(int** arr)//����  ����������int* �ĵ�ַ������int**������
//{}
//int main()
//{
//	int arr[10] = { 0 };
//
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}

////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
////��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
////�����ŷ������㡣
//
//void test(int arr[3][5])//����
//{}
//void test(int arr[][])//�����ԣ�ֻ��ʡ���У�����ʡ����
//{}
//void test(int arr[][5])//����
//{}
//									
//void test(int* arr)//������
//{}
//void test(int* arr[5])//������
//{}
//void test(int(*arr)[5])//����
//{}
//void test(int** arr)//������
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);
//}

//void print(int* p, int sz)  //�βεĲ���д��һ��ָ�������
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* pa = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//һ��ָ��p����������
//	print(pa, sz);
//	return 0;
//}

void test(int** ptr)
{
	printf("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);//���������Ƕ���ָ��
	test(&p);
	return 0;
}