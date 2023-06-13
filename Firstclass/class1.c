#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int a = 0;
//	{
//		int b = 1;
//		printf("%d,%d", a, b);//由此正常使用可知：b出了作用域后就销毁了
//	}
//	printf("%d,%d", a, b);//a可以正常使用，但是b不行，因为局部变量的作用域在{  }之间；
//	return 0;
//}
//
//int a = 0;//全局变量生命周期在整个工程
//int main()
//{
//	printf("%d", a);
//	return 0;
//}


//int main()
//{
//	/*int a = 0;
//	printf("%d", a);
//	a = 110;
//	printf("%d", a);*/  //完全没问题
//
//
//	//const int a = 0;
//	//printf("%d", a);
//	//a = 110;//使用了const  a为常变量，不是常量，只是不能改了
//	//printf("%d", a);
//
//	return 0;
//}

//枚举常量
//enum Color
//{
//	RED, //0
//	GREEN,  //1
//	BLUE  //2
//};
//int main()
//{
//	enum Color a = RED;
//	printf("%d", a);//结果是0(默认时）
//	return 0;
//}