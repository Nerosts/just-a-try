#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>


struct message
{
	std::string info;//���͵���Ϣ
	std::string nickname;//�����ߵ��ǳ�
	std::string time;//���͵�ʱ��
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