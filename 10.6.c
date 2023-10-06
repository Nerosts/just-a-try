//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 7;//创建变量时，在内存里开辟的一篇空间
//	int* pa = &a;//这里我们对变量a，取出它的地址，可以使用&操作符
//	//a变量占用4个字节的空间，这里是将a的4个字节的第一个字节的地址存放在p变量
//	//中，p就是一个之指针变量
//	return 0;
//}
//
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}
//
//int main()
//{
//	int* pa;
//	*pa = 10;
//	return 0;
//}
//
//int* createInt() {
//	int num = 5;
//	int* ptr = &num;
//	return ptr;
//}
//
//int main() {
//	int* ptr = createInt();
//	printf("%d\n", *ptr);  // 输出5，但是这是不安全的操作
//
//	// 在这之后，ptr成为了野指针，因为它指向的内存空间已经被释放
//
//	printf("%d\n", *ptr);  // 未定义的行为，可能输出垃圾值或导致程序崩溃
//
//	return 0;
//}