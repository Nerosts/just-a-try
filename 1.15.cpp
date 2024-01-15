#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

namespace Test2
{
	int b = 0;
	namespace Test2_1//这里命名空间嵌套
	{
		int a = 1;
	}
}
using Test2::b;
int main()
{
	printf("%d\n", b);
	printf("%d\n",Test2:: Test2_1::a);//这样访问a
	return 0;
}