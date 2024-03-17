#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>

using namespace std;

void testmap1()
{
	map<string, string> m1;//�յ�
	map<string, string> m2(m1);//��������
}

void testmap2()
{
	map<string, string> m1;//�յ�
	
	m1.insert(pair<string, string>("sort", "����"));//��������
	m1.insert(make_pair("apple", "ƻ��"));//ʹ��make_pair����
	m1.insert({ "apple", "ƻ��" });// C++11 �������ʽ����ת��(���캯��֧��)
}
void testmap3()
{
	map<string, string> m1;//�յ�

	m1.insert(pair<string, string>("sort", "����"));//��������
	m1.insert(make_pair("apple", "ƻ��"));//ʹ��make_pair����
	m1.insert({ "left", "���" });// C++11 �������ʽ����ת��(���캯��֧��)
	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;

	m1["right"];//���ǲ���һ��right��key��
	m1["apple"] = "��ƻ��";//�����ǽ����޸�

	for (auto& kv : m1)
	{
		cout << kv.first << ":" << kv.second << " ";
	}
	cout << endl;
}

int main()
{
	testmap3();
	return 0;
}