#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//
//����ż��λ������ĺ�벿�֡�
//void change(int* arr)
//{
//	int* destination = arr + 1;
//	int* odd = arr + 2;
//	while (destination < arr + 3)
//	{
//		int t = *odd;
//		*odd = *destination;
//		*destination = t;
//		odd=odd + 2;
//		destination=destination + 1;
//	}		
//}
//
//
//int main()
//{
//	int arr[6] = { 1,2,3,4,5,6 };
//	
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	change(arr);
//	printf("\n");
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ģ��ʵ��strcpy
//char* my_strcpy(char* des, const char* cors)
//{
//	assert(*des);
//	assert(*cors);
//	while (*des++ = *cors++)
//	{
//		;
//	}
//	
//	return des;
//}
//
//
//int main()
//{
//	char arr1[] = "***********";
//	char arr2 []= "abcdef";
//	printf("%s\n", arr1);
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//}

//ģ��ʵ��strlen;
//size_t my_strlen(const char* a)
//{
//	assert(a);
//	size_t count = 0;
//	while (*a)
//	{
//		count++;
//		a++;
//	}
//	return count;
//}
//
//
//int main()
//{
//	char arr[] = "abcdef";
//	size_t se =my_strlen(arr);
//	printf("%zd", se);
//	return 0;
//}

//int main()
//{
//	//��Ҫע����ǣ������±��Ǵ�0��ʼ��
//	char arr1 []= "hello";
//	char arr2[] = { 'h','e','l','l','o' };
//	//��Ӧ���±꣺   0   1   2   3   4
//
//	printf("%c", arr2[0]);//�����һ��h������
//
//	return 0;
//}
//int main()
//{
//	int arr1[3][4] = { 1,2,3,4 };//���ֳ�ʼ����һ�����˺�ͻ�����һ��
//	int arr2[3][4] = { {1,2},{4,5} };//���ֳ�ʼ���Ѿ��涨һ�е�Ԫ�أ�����������0
//	int arr3[][4] = { {2,3},{4,5} };//��Ҫע����ǣ���ά��������г�ʼ�����п���ʡ�ԣ��в���ʡ��
//
//	return 0;
//}
//int main()
//{
//	int arr[2][3] = { {1,4},{2,3} };
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int arr[3][4];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d]�ĵ�ַ�ǣ� %p\n", i, j, &arr[i][j]);
//		}
//	}
//	return 0;
//}

int main()
{
	int arr[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i <= 10; i++)
	{
		printf("arr[%d]=%d\n",i, arr[i]);//��i����10��ʱ��Խ�������
	}
	return 0;
}
