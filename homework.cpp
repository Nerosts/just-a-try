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
//	cout << "�����������ǣ�" << s1.volume(x) << "\n";
//	cout << "������ı�����ǣ�" << s1.surface(x) << "\n";
//	return 0;
//}

class judge {
public:
	judge() {
		cout << "�������޲εĹ��캯��\n";
	}
	judge(int x) {
		cout << "������  ��  �εĹ��캯��\n";
	}
	~judge();
private:
	int x;
};

judge::~judge() {
	cout << "��������������\n";
}

int main()
{
	judge a;
	judge b(2);
	return 0;
}