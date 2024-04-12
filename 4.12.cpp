#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<stdio.h>
//#include<unistd.h>
//#include<sys/types .h>
//int main(int argc, char* argv[])
//{
//	/*for (int i = 0; i < argc; i++)
//	{
//		printf("%s\n", argv[i]);
//	}*/
//
//	printf("%s\n", NULL);
//
//	return 0;
//}


int main(int argc, char* argv[])
{
    if (argc == 4)
    {
        int a = atoi(argv[2]);//×Ö·û´®×ªint
        int b = atoi(argv[3]);//×Ö·û´®×ªint

        if (strcmp(argv[1], "-add") == 0)
        {
            printf("%d+%d=%d\n", a, b, a + b);
        }
        else if (strcmp(argv[1], "-sub") == 0)
        {
            printf("%d-%d=%d\n", a, b, a - b);
        }
        else if (strcmp(argv[1], "-mul") == 0)
        {
            printf("%d*%d=%d\n", a, b, a * b);
        }
        else
        {
            printf("%d/%d=%d\n", a, b, a / b);
        }
    }
    else
    {
        printf("used wrongly:please ./code.c [add][sub][mul][div] num1 num2");
        return 1;
    }
    return 0;
}

