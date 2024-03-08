#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>

using namespace std;

void test1()
{
	map<string, string> dict;
	dict.insert({ "sort","����" });
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}
}
//��һ��
void test2()
{
	string fruit[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "����", "�㽶", "��ݮ" };

	map<string, int> countMap;
	for (auto& e : fruit)
	{
		map<string, int>::iterator it = countMap.find(e);
		if (it == countMap.end())
		{
			countMap.insert({ e,1 });
		}
		else
		{
			it->second++;
		}
	}

	for (auto& e : countMap)
	{
		cout << e.first << " :" << e.second;
		cout << endl;
	}
}
//�ڶ���
void test3()
{
	string fruit[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "����", "�㽶", "��ݮ" };

	map<string, int> countMap;
	for (auto& e : fruit)
	{
		//�Ȳ����
		pair<map<string, int>::iterator, bool> ib;
		ib = countMap.insert({ e,1 });
		if (ib.second == false)//˵������
		{
			ib.first->second++;
		}
	}

	for (auto& e : countMap)
	{
		cout << e.first << " :" << e.second;
		cout << endl;
	}
}
//������
void test4()
{
	string fruit[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "����", "�㽶", "��ݮ" };

	map<string, int> countMap;
	for (auto& e : fruit)
	{
		countMap[e]++;//��nb
	}

	for (auto& e : countMap)
	{
		cout << e.first << " :" << e.second;
		cout << endl;
	}
}

int main()
{
	test4();
	return 0;
}