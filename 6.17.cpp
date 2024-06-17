#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>


struct message
{
	std::string info;//发送的信息
	std::string nickname;//发送者的昵称
	std::string time;//发送的时间
};

struct A
{
	int a;
	int b;
	char c;
	double d;
};

int main()
{
	//std::string send = "info-nickname-time";
	A a;
	memset(&a, 0, sizeof(A));
	return 0;
}