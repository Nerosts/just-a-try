#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d", 2 + 4 * (n / 12));
//    return 0;
//}


//����10��������Ҫ������ʱ���������10������ӡ������������������ǰ��������෴��˳���ӡ��10������
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

//BoBo��KiKi�ַ��������ַ�������ʾ���ַ����ڴ�����ASCII����ʽ�洢��BoBo����һ�������KiKi��ת������ASCII��Ϊ��Ӧ�ַ���������ǡ�

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