#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//char* my_strstr(const char* a1, const char* a2)
//{
//	char* cp = a1;
//	char* str1 = a1;
//	char* str2;
//
//	while (*cp)
//	{
//		str1 = cp;
//		str2 = a2;
//		while (*str1&&*str2&&*str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		if (*str2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cd";
//	printf("%s", my_strstr(arr1, arr2));
//	return 0;
//}

//int main()
//{
//	char arr[] = "123@abc%ABC";
//	char a[] = "@%";
//	/*printf("%s\n", strtok(arr, a));
//	printf("%s\n", strtok(NULL, a));
//	printf("%s\n", strtok(NULL, a));*/
//
//	for (char* ret = strtok(arr, a); ret != NULL;ret= strtok(NULL, a))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i <= 10; i++)
//	{
//		printf("%s\n", strerror(i));
//	}
//	return 0;
//}

//int main() 
//{
//    char src[] = "Hello, world!";
//    char dest[20];
//
//    memcpy(dest, src, strlen(src) + 1);
//
//    printf("source string: %s\n", src);
//    printf("copied string: %s\n", dest);
//    return 0;
//}

//int main() 
//{
//    char str[] = "123456";
//    memmove(str,str+3,3);
//    printf("%s\n", str);
//    return 0;
//}

//int main() 
//{
//    char str[20] = { 0 };
//    memset(str, 'A', 10);
//    printf("%s\n", str);
//    return 0;
//}

int main() 
{
    char str1[20] = "Hello, world!";
    char str2[20] = "Hello, world!";
    int result1 = memcmp(str1, str2, strlen(str1));
   
    printf("result = %d\n", result1);
    return 0;
}