#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//size_t my_strlen(char* pa)
//{
//	assert(pa);
//	int count = 0;
//	while (*pa)
//	{
//		count++;
//		pa++;
//	}
//	return count;
//}

//size_t my_strlen(char* pa)
//{
//	if (*pa)
//	{
//		return my_strlen(pa + 1) + 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//size_t my_strlen(char* pa)
//{
//	char* start = pa;
//	while (*pa)
//	{
//		pa++;
//	}
//	return pa - start;
//}
//
//
//int main()
//{
//	char arr[] = "hello";
//	printf("%s的长度是%d", arr, my_strlen(arr));
//	return 0;
//}

//char* my_strcpy(char* dest, char* src)
//{
//    while (*src)
//    {
//        *dest = *src;
//        dest++;
//        src++;
//    }
//    *dest = *src;
//}

//char* my_strcpy(char* dest, char* src)
//{
//    char* ret = dest;
//    while (*dest++ = *src++)
//    {
//        ;
//    }
//    return ret;
//}
//
//
//int main() 
//{
//    char src[] = "Hello, world!";
//    char dest[20];
//    my_strcpy(dest, src);
//    printf("The copied string is: %s\n", dest);
//    return 0;
//}

//char* my_strcat(char* dest, char* src)
//{
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*src)
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = " world";
//	printf("%s", my_strcat(arr1, arr2));
//	return 0;
//}

//int my_strcmp(char* arr1, char* arr2)
//{
//    while (*arr1 == *arr2)
//    {
//        if (*arr1 == '\0' && *arr2 == '\0')
//        {
//            return 0;
//        }
//        arr1++;
//        arr2++;
//    }
//    return *arr1 - *arr2;
//}
//
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "aec";
//    int result = my_strcmp(arr1, arr2);
//
//    if (result < 0) {
//        printf("arr1 is less than arr2\n");
//    }
//    else if (result > 0) {
//        printf("arr1 is bigger than arr2\n");
//    }
//    else {
//        printf("arr1 is equal to arr2\n");
//    }
//	return 0;
//}

//int main() 
//{
//    char src[] = "Hello, World!";
//    char dest[20];
//
//    strncpy(dest, src, 5);
//    dest[5] = '\0';
//
//    printf("Copied string: %s\n", dest);
//
//    return 0;
//}
