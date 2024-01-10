#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int globalVar = 1;//全局变量，在静态区
static int staticGlobalVar = 1;//全局静态变量，在静态区

//int main()
//{
//	static int staticVar = 1;//局部静态变量，在静态区。作用域只在这个函数内，但是生命周期是在整个程序
//	int localVar = 1;//局部变量，在栈
//	int num1[10] = { 1, 2, 3, 4 };//局部变量，在栈
//
//	char char2[] = "abcd"; //局部变量，在栈。
//	//其实[]这个符号：是把位于常量区的"abcd"，拷贝到栈上，再去指向
//
//	const char* pChar3 = "abcd";//pChar3在栈上，但是是直接指向常量区的"abcd"。所以*pChar3在常量区
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1这个指针变量还是在栈，但是*ptr1是在堆上
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//
//	return 0;
//}

//int main()
//{
//	 动态申请一个int类型的空间
//	int* a = new int;
//
//	 动态申请一个int类型的空间并初始化为11
//	int* b = new int(11);
//
//	 动态申请3个int类型的空间
//	int* c = new int[3];
//
//	 动态申请10个int类型的空间，并进行部分初始化
//	int* d = new int[10]{ 1,2,3 };
//
//
//	delete a;
//	delete b;
//	delete[] c;
//	delete[] d;
//	return 0;
//}

class A
{
public:
	A(int a=0)
		:_a(a)
	{}
	~A()
	{
		cout << "调用了~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//	//动态申请一个A类型的空间
//	A* pa1 = new A(1);
//
//	//动态申请3个A类型的空间
//	A a1;
//	A a2;
//	A a3;
//	A* pa2 = new A[3]{ a1, a2, a3 };
//	//可以直接写成以下两种
//	A* pa3 = new A[3]{ A(1), A(2), A(3) };//匿名对象
//	//再少点
//	A* pa4 = new A[3]{ 1,2 ,3 };//隐式类型转换，有单形参的构造函数支持
//
//	delete pa1;
//	delete[] pa2;
//	delete[] pa3;
//	return 0;
//}

int main()
{
	A*
	return 0;
}