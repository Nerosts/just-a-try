#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d", 2 + 4 * (n / 12));
//    return 0;
//}


//输入10个整数，要求按输入时的逆序把这10个数打印出来。逆序输出，就是按照输入相反的顺序打印这10个数。
//int main() {
//    int arr[10] = { 0 };
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (int j = 9; j >= 0; j--)
//    {
//        printf("%d ", arr[j]);
//    }
//    return 0;
//}


int main()
{
	char ar = '1';
	printf("%c", '2');
	return 0;
}

//BoBo教KiKi字符常量或字符变量表示的字符在内存中以ASCII码形式存储。BoBo出了一个问题给KiKi，转换以下ASCII码为对应字符并输出他们。

//73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33

int main() {
    int arr[] = { 73,32,99,97,110,32,100,111,32,105,116,33 };
    int length = sizeof(arr) / sizeof(arr[1]);
    for (int i = 0; i < length; i++)
    {
        printf("%c", arr[i]);
    }
    return 0;
}