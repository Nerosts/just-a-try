#define _CRT_SECURE_NO_WARNINGS 1
#define ADD(x,y) ((x)+(y))
#include<iostream>
using namespace std;

int& count (int a,int b)
{
	static int c;
	c = a + b;
	return c;
}

//int main()
//{
//	int& ret=count(1,2);
//	cout << ret<<endl;
//	count(3, 3);
//	//cout << ret;
//	cout << count(6,6);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << a << endl;
//	b = 1;
//	cout << a << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;//定义引用类型
//	printf("%p\n", &a);
//	printf("%p\n", &ra);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	const int& ra = a;//这样也可以，不会报错
//	return 0;
//}

int main()
{
	int a = 10;
	const double& b = a;
	return 0;
}

