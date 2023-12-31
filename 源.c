#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//定义一个全局变量
int rand = 1;

int main()
{
   // srand(time(0));
    printf("%d\n", rand);
    return 0;
}