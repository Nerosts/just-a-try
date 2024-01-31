#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"list.h"


//
int main()
{
	MyList::test2();
	return 0;
}

//int& Add(int a, int b)
//{
//    static int c = a + b;
//    return c;
//}
//int main()
//{
//    int ret = Add(1, 2);
//    cout << "Add(1, 2) is :" << ret << endl;
//    int& m = Add(3, 4);
//    cout << "Add(3, 4) is :" << m << endl;
//    return 0;
//}