#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main() 
//{
//    char dest[20] = "Hello, ";
//    char src[] = "World!";
//    strncat(dest, src, 5);
//    printf("Connected string: %s\n", dest);
//    return 0;
//}

int main() {
    char str1[] = "Hello";
    char str2[] = "Hell";

    int result = strncmp(str1, str2, 4);

    if (result == 0) 
    {
        printf("The first 4 characters of str1 and str2 are equal.\n");
    }
    else if (result < 0) 
    {
        printf("The first different character in str1 is smaller than the corresponding character in str2.\n");
    }
    else 
    {
        printf("The first different character in str1 is bigger than the corresponding character in str2.\n");
    }

    return 0;
}