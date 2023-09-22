#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//// 定义一个函数
//int add(int a, int b) {
//    return a + b;
//}
//
//int main()
//{
//    // 声明一个函数指针
//    int (*funcPtr)(int, int);
//
//    // 将函数指针指向add函数
//    funcPtr = add;
//
//    // 通过函数指针调用函数
//    int result = funcPtr(2, 3);  // 结果为5   平时调用函数时都是函数名（地址），也可以想通
//    int result = (*funcPtr)(2, 3);  // 这两种均可以，funcPtr是地址，通过*解引用来找到
//    return 0;
//}

//    (*(void (*)())0)();

//void (*signal(int , void(*)(int)))(int);

// 定义函数1
//void func1(int num) {
//    printf("This is function 1. Number: %d\n", num);
//}
//
//// 定义函数2
//void func2(int num) {
//    printf("This is function 2. Number: %d\n", num);
//}

// 定义函数3
//void func3(int num) {
//    printf("This is function 3. Number: %d\n", num);
//}
//
//int main() {
//    // 将函数指针赋值给函数指针数组的元素
//    void(*pf[3])(int) = { &func1,&func2, &func3 };
//
//    // 调用函数指针数组中的函数
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
//        printf("请输入:\n");
//        scanf("%d", &input);//根据menu来输入数字啦
//        int(*pf[5])(int, int) = { NULL,add,sub,mul,div };//第一个是NUll是为了使数字与菜单对应
//        if (input >= 1 && input <= 4)
//        {
//            printf("请输入两个数\n");
//            scanf("%d %d", &a, &b);
//            result = pf[input](a, b);
//            printf("%d\n", result);
//        }
//        else if(input==0)
//        {
//            printf("退出计算器");
//        }
//        else
//        {
//            printf("输入有误，请重新输入");
//        }
//    }
//    return 0;
//}

int add(int x, int y)
{
    return x + y;
}

// 定义一个回调函数
void callback(int result) 
{
    printf("回调函数被调用，结果为：%d\n", result);
}

// 定义一个函数，接受一个函数指针作为参数
void performOperation(int (*operation)(int, int), int a, int b, void (*callback)(int)) 
{
    int result = operation(a, b);
    callback(result);
}

int main()
{
    // 调用函数，并传递回调函数作为参数
    performOperation(add, 2, 3, callback);
	return 0;
}