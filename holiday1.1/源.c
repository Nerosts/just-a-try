#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != '\n') {
//		printf("%c", ch);
//	}
//	return 0;
//}
typedef unsigned int uint;
//int main()
//{
//	uint a = 10;
//	printf("%d", a);
//	return 0;
//}
//int main()
//{
//	//�����������ļ��ﶨ���˵ı�����������ļ���ֱ�����ǲ��е�
//	//ֻ����extern�����������������
//	 int a;
//	 while ((scanf("%d", &a) != EOF)) {
//		 printf("%d", a);
//	}
//	return 0;
//}


//С���ֻ��4������������������ҵ���������
//����������
//һ�У�4���������ÿո�ֿ���
//���������
//һ�У�һ��������Ϊ�����4������������������
//int main() {
//    int a, b, c, d;
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//    int max = a;
//    if (b > max) {
//        max = b;
//    }
//    if (c > max) {
//        max = c;
//    }
//    if (d > max) {
//        max = d;
//    }
//    printf("%d", max);
//    return 0;
//}


//KiKi�������ĸ��Сдת������һ���ַ����ж����Ƿ�Ϊ��д��ĸ������ǣ�����ת����Сд��ĸ����֮��ת��Ϊ��д��ĸ��
//����������
//�������룬ÿһ������һ����ĸ��
//���������
//���ÿ�����룬�������ռһ�У������ĸ�Ķ�Ӧ��ʽ��
//int main() {
//    int a, b;
//    char c;
//    while (scanf("%c", &c) != EOF) {
//        if (c >= 'a' && c <= 'z') {
//            printf("%c\n", c - 32);
//        }
//        if (c >= 'A' && c <= 'Z') {
//            printf("%c\n", c + 32);
//        }
//
//
//    }
//    return 0;
//}
//KiKi���ж�������ַ��ǲ�����ĸ����������ʵ�֡�
//
//����������
//�������룬ÿһ������һ���ַ���
//���������
//���ÿ�����룬�������ռһ�У��ж������ַ��Ƿ�Ϊ��ĸ���������������������
int main() {
    int a, b;
    char c;
    while (scanf("%c", &c) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            printf("%c is an alphabet.\n", c);
        }
        else {
            printf("%c is not an alphabet.\n", c);
        }
       //getchar();
    }
    return 0;
}