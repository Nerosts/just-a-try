#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;//�ղι���

	vector<int> v2(5, 1);//���첢��ʼ��5��1

	vector<int> v3(v2);//��������

	string s1("abc");
	vector<int> v4(s1.begin(), s1.end());//ʹ�õ��������г�ʼ������

	return 0;
}