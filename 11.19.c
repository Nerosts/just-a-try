#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	long s = 0, n, k, i;
	scanf_s("%d", &n);
	k = 2 * n - 1;
	i = 1;
	while (i <= k)
	{
		s += i;
		i++;
	}
	printf("1+3+...+%1d=%1d\n", k, s);
}