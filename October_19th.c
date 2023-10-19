#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdio.h>
//int main()
//{
//	FILE* pf1 = fopen("date1.txt", "r");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//
//	}
//	FILE* pf2 = fopen("date2.txt", "w");
//	if (pf1 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//¿ªÊ¼copy
//	int ch;
//	while ((ch = fgetc(pf1)) != EOF)
//	{
//		fputc(ch, pf2);
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		if()
//	}
//	return 0;
//}

//int main()
//{
//	int arr[9][9] = { 0 };
//	
//
//	 for (int i = 0; i < 9; i++)
//	 {
//		 for (int j = 0; j <= i; j++)
//		 {
//			 if (j == 0 || i == j)
//			 {
//				 arr[i][j] = 1;
//			 }
//		 }
//	 }
//	 for (int i = 2; i < 9; i++)
//	 {
//		 for (int j = 1; j <i; j++)
//		 {
//			 arr[i][j] = arr[i - 1][j - 1] + arr[i-1][j];
//		 }
//	 }
//	 for (int i = 0; i < 9; i++)
//	 {
//		 for (int j = 0; j <= i; j++)
//		 {
//			 printf("%-3d ", arr[i][j]);
//		 }
//		 printf("\n");
//	 }
//	return 0;
//}
//char* zhuan(char arr[], int n)
//{
//	char c = '0';
//	int i = 0;
//	while (n--)
//	{
//		c = arr[0];
//		for (int j = 0; j < strlen(arr)-1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[5] = c;
//		
//	}
//	return arr;
//}
void ni(char* left,char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

char* zhuan(char arr[], int n)
{
	ni(arr, arr + n - 1);
	ni(arr + n, arr + strlen(arr) - 1);
	ni(arr, arr + strlen(arr) - 1)
	return arr;
}

int main()
{
	char arr[] = "abcdef";
	printf("%s", zhuan(arr, 2));
	return 0;
}