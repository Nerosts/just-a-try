#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class square {
//public:
//	square(){}
//	square(int length) {
//		x = length;
//	}
//
//	int volume(int length)
//	{
//		return length * length * length;
//	}
//
//	int surface(int length) {
//		return 6* length * length;
//	}
//private:
//	int x;
//};
//
//int main()
//{
//	int x = 0;
//	cin >> x;
//	square s1(x);
//	cout << "正方体的体积是：" << s1.volume(x) << "\n";
//	cout << "正方体的表面积是：" << s1.surface(x) << "\n";
//	return 0;
//}

class judge {
public:
	judge() {
		cout << "调用了无参的构造函数\n";
	}
	judge(int x) {
		cout << "调用了  有  参的构造函数\n";
	}
	~judge();
private:
	int x;
};

judge::~judge() {
	cout << "调用了析构函数\n";
}

int main()
{
	judge a;
	judge b(2);
	return 0;
}