#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//����ָ��
//int sum(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int(*p)(int, int) =&sum;
//	int ret = (*p)(3, 4);
//	printf("%d", (*p)(a, b));
//	printf("%d", ret);
//	return 0;
//}
//
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//char* revolve(char* arr, int num)
//{
//	int right = strlen(arr) - 1;
//	char* ret = (char*)malloc(sizeof(char) * strlen(arr));
//	while (num--)
//	{
//		int i = 1;
//		int a = arr[0];
//		for ( i = 1; i <= right ; i++)
//		{
//			ret[i - 1] = arr[i];
//		}
//		ret[i] = a;
//		arr = ret;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	int num = 1;
//	printf("%s",revolve(arr, num));
//	return 0;
//}
//void revolve(char* arr, int num)
//{
//	int right = strlen(arr) - 1;
//
//	/*printf("%d", right);*/
//	while (num--)
//	{
//		int a = arr[0];
//		for (int i = 1; i <= right; i++)
//		{
//			arr[i - 1] = arr[i];
//		}
//		arr[right] = a;
//	}
//}
//
//int main()
//{
//	char arr[] = "ABCD";
//	int num = 1;
//	revolve(arr, num);
//	printf("%s", arr);
//	return 0;
//}

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
int judge(char* s1, char* s2)
{
	int flag = 0;
	int len = strlen(s1);
	while (len--)
	{
		int a = s1[0];
		int i = 1;
		for (i = 1; i < len; i++)
		{
			s1[i - 1] = s1[i];
		}
		s1[len - 1] = a;
		if (strcmp(s1, s2) == 0)
		{
			flag = 1;
			break;
		}
		/*len--;*/
	}
	return flag;
}
int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	printf("%d",judge(s1, s2));
	return 0;
}