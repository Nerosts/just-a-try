#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<set>
#include<map>

using namespace std;

void test1()
{
	map<string, string> dict;
	dict.insert({ "sort","排序" });
	map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << " " << it->second << endl;
		it++;
	}
}
//第一种
void test2()
{
	string fruit[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "西瓜", "香蕉", "草莓" };

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
//第二种
void test3()
{
	string fruit[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "西瓜", "香蕉", "草莓" };

	map<string, int> countMap;
	for (auto& e : fruit)
	{
		//先插进来
		pair<map<string, int>::iterator, bool> ib;
		ib = countMap.insert({ e,1 });
		if (ib.second == false)//说明有了
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
//第三种
void test4()
{
	string fruit[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "西瓜", "香蕉", "草莓" };

	map<string, int> countMap;
	for (auto& e : fruit)
	{
		countMap[e]++;//很nb
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