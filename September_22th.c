#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//// ����һ������
//int add(int a, int b) {
//    return a + b;
//}
//
//int main()
//{
//    // ����һ������ָ��
//    int (*funcPtr)(int, int);
//
//    // ������ָ��ָ��add����
//    funcPtr = add;
//
//    // ͨ������ָ����ú���
//    int result = funcPtr(2, 3);  // ���Ϊ5   ƽʱ���ú���ʱ���Ǻ���������ַ����Ҳ������ͨ
//    int result = (*funcPtr)(2, 3);  // �����־����ԣ�funcPtr�ǵ�ַ��ͨ��*���������ҵ�
//    return 0;
//}

//    (*(void (*)())0)();

//void (*signal(int , void(*)(int)))(int);

// ���庯��1
//void func1(int num) {
//    printf("This is function 1. Number: %d\n", num);
//}
//
//// ���庯��2
//void func2(int num) {
//    printf("This is function 2. Number: %d\n", num);
//}

// ���庯��3
//void func3(int num) {
//    printf("This is function 3. Number: %d\n", num);
//}
//
//int main() {
//    // ������ָ�븳ֵ������ָ�������Ԫ��
//    void(*pf[3])(int) = { &func1,&func2, &func3 };
//
//    // ���ú���ָ�������еĺ���
//    for (int i = 0; i < 3; i++) {
//        pf[i](i);
//    }
//    return 0;
//}
//void menu()
//{
//    printf("******************************\n");
//    printf("***   1.add        2.sub   ***\n");
//    printf("***   3.mul        4.div   ***\n");
//    printf("***   0.exit       ***********\n");
//    printf("******************************\n");
//}
//

//int sub(int x, int y)
//{
//    return x - y;
//}
//int mul(int x, int y)
//{
//    return x * y;
//}
//int div(int x, int y)
//{
//    return x / y;
//}
//
//
//int main()
//{
//    int input = 1;
//    int result = 0;
//    int a = 0;
//    int b = 0;
//    while (input)
//    {
//        menu();
//        printf("������:\n");
//        scanf("%d", &input);//����menu������������
//        int(*pf[5])(int, int) = { NULL,add,sub,mul,div };//��һ����NUll��Ϊ��ʹ������˵���Ӧ
//        if (input >= 1 && input <= 4)
//        {
//            printf("������������\n");
//            scanf("%d %d", &a, &b);
//            result = pf[input](a, b);
//            printf("%d\n", result);
//        }
//        else if(input==0)
//        {
//            printf("�˳�������");
//        }
//        else
//        {
//            printf("������������������");
//        }
//    }
//    return 0;
//}

int add(int x, int y)
{
    return x + y;
}

// ����һ���ص�����
void callback(int result) 
{
    printf("�ص����������ã����Ϊ��%d\n", result);
}

// ����һ������������һ������ָ����Ϊ����
void performOperation(int (*operation)(int, int), int a, int b, void (*callback)(int)) 
{
    int result = operation(a, b);
    callback(result);
}

int main()
{
    // ���ú����������ݻص�������Ϊ����
    performOperation(add, 2, 3, callback);
	return 0;
}