#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����������ʱ������������������������
//int main()
//{
//	int a = 10;
//	int b = 5;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//	return 0;
//}
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//int main()
//{
//	int a = 10;
//	printf("ż��λ��");
//	for (int i = 0; i < 32; i += 2)
//	{
//		printf("%d ", (a >> i) & 1);
//		
//	}
//	printf("\n");
//	printf("����λ��");
//	for (int i = 1; i <= 31; i += 2)
//	{
//		printf("%d ", (a >> i) & 1);
//		
//	}
//	return 0;
//}

//KiKi����ĳ��ĳ���ж����죬��������ʵ�֡�������ݺ��·ݣ�������һ��������ж����졣
//����������
//�������룬һ���������������ֱ��ʾ��ݺ��·ݣ��ÿո�ָ���
//���������
//���ÿ�����룬���Ϊһ�У�һ����������ʾ��һ��������ж�����
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) {
//        if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12)
//        {
//            printf("%d\n", 31);
//        }
//        else if (b == 2) {
//            if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
//            {
//                printf("%d\n", 29);
//            }
//            else {
//                printf("%d\n", 28);
//            }
//        }
//        else {
//            printf("%d\n", 30);
//        }
//    }
//
//    return 0;
//}

//����ˮ�ɻ��� - Lily Number������������֣����м��ֳ��������֣�����1461 ���Բ�ֳɣ�1��461��, ��14��61��, ��146��1), ������в�ֺ�ĳ˻�֮�͵�����������һ��Lily Number��
//
//���磺
//
//655 = 6 * 55 + 65 * 5
//
//1461 = 1 * 461 + 14 * 61 + 146 * 1
//
//��� 5λ���е����� Lily Number��
//
//����������
//��
//���������
//һ�У�5λ���е����� Lily Number��ÿ������֮����һ���ո�
//int main() {
//    for (int i = 10000; i <= 99999; i++)
//    {
//        int a1 = (i % 10) * (i / 10);
//        int a2 = (i % 100) * (i / 100);
//        int a3 = (i % 1000) * (i / 1000);
//        int a4 = (i % 10000) * (i / 10000);
//        if (a1 + a2 + a3 + a4 == i)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}
//void changeValue(int ptr) {
//    ptr = 10;
//    printf("Inside function: %d\n", ptr);
//}
//
//int main() {
//    int x = 5;
//    printf("Before function call: %d\n", x);
//
//    changeValue(x);
//
//    printf("After function call: %d\n", x);
//
//    return 0;
//}
//
//void changeValue(int* ptr) {
//    *ptr = 10;
//    printf("Inside function: %d\n", *ptr);
//}
//
//int main() {
//    int x = 5;
//    printf("Before function call: %d\n", x);
//
//    changeValue(&x);
//
//    printf("After function call: %d\n", x);
//
//    return 0;
//}
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	return 0;
}