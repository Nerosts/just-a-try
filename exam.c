#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>

//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int flag = 0;
//    char arr[20] = { 0 };
//int i = 0;
//    while (n)
//    {
//        
//        arr[i] = (char)(n % 10);
//        i++;
//        n = n / 10;
//        flag++;
//        if (flag % 3 == 0)
//        {
//            arr[i] = ',';
//            i++;
//        }
//    }
//printf("%s", arr);
//    /*for (int i = strlen(arr) - 1; i > -1; i--)
//    {
//        
//    }*/
//    return 0;
//}\

#include <stdlib.h>
#include <string.h>

//int find(char* arr2, char ch)
//{
//    for (int i = 0; i < strlen(arr2); i++)
//    {
//        if (*(arr2) == ch)
//        {
//            return 1;
//        }
//    }
//    return 0;
//}
//
//int main() {
//    char* arr1 = (char*)malloc(sizeof(char) * 100);
//    char* arr2 = (char*)malloc(sizeof(char) * 100);
//
//    scanf("%s", arr1);
//    scanf("%s", arr2);
//    int i = 0;
//    while (*(arr1) != '\0')
//    {
//        if (find(arr2, arr1[i]) == 1&&arr1[i+1]!='\0')
//        {
//            
//                arr1[i] = arr1[i + 1];
//               
//            if (i + 1 == strlen(arr1) - 1)
//            {
//                arr1[i + 1] = '\0';
//
//            }
//            
//        }
//        else {
//            i++;
//        }
//    }
//    printf("%s", arr1);
//    return 0;
//}

int main()
{
	char arr1[100] = { 0 };
	gets(arr1);
	for (int i = 0; i < strlen(arr1) - 1; i++)
	{
		arr1[i] = 'a';
		printf("%c ", arr1[i]);
	}
	return 0;
}
