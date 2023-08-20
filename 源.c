#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
//写一个函数打印arr数组的内容，不使用数组下标，使用指针。
//
//arr是一个整形一维数组
void print(int arr[],int le)
{
	
	
}

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	int* a = arr;
//	for (int i = 0; i <sizeof(arr)/sizeof(arr[1]); i++)
//	{
//		printf("%d ", *(a + i));
//	}
//	return 0;
//}

//写一个函数，可以逆序一个字符串的内容
//int main() {
//	char arr[10000];
//	scanf("%s", arr);
//	return 0;
//}
//int main() {
//    char in[10000];
//    gets(in);
//    char* a = in;
//    for (int i = strlen(in) - 1; i >= 0; i--) {
//        printf("%c", *(a + i));
//    }
//}
//
//int main()
//{
//	int k = 0;
//
//	for (int i = 1; i <= 6; i++)
//	{
//		//打印空格
//		for (int j = 1; j <= 6 - i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 5; i >= 1; i--)
//	{
//		for (int j = 1; j <= 6 - i; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= 2 * i - 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//		
//	}return 0;
//}
//int isArmstrongNumber(int num) {
//    int originalNum = num;
//    int sum = 0;
//    int numDigits = 0;
//
//    while (num) {
//        num /= 10;
//        numDigits++;
//    }
//
//    num = originalNum;
//
//    while (num) {
//        sum += pow(num % 10, numDigits);
//        num /= 10;
//    }
//
//    if (sum == originalNum) {
//        return 1; 
//    }
//    else {
//        return 0;
//    }
//}
//
//int main() {
//    for (int i=  0; i <= 100000; i++) {
//        if (isArmstrongNumber(i)) {
//            printf("%d\n", i);
//        }
//    }
//
//    return 0;
//}
//int sum(int a)
//{
//	if (a <= 9)
//	{
//		return a;
//	}
//	else
//	{
//		return a + sum(a / 10);
//	}
//}
//
//int main()
//{
//	int a = 22222;
//	printf("%d", sum(a));
//	return 0;
//}
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。

//{
//	int sum = 0;
//	if (a >= 2)
//	{
//		sum += a;
//		return sum + calculate(a / 2);
//	}
//	else
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int kole = 20;
//	
//	printf("%d", calculate(kole));
//	return 0;
//}
int main()
{
    int i = 0;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (i = 0; i <= 12; i++)
    {
        arr[i] = 0;
        printf("hello bit\n");
    }
    return 0;
}