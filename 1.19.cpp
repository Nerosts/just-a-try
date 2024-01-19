#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	//±éÀú
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	vector<int> v1;
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	vector<int> v2(2, 3);
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	vector<int> v3(v2.begin(), v2.end());
//	for (auto e : v3)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	string s1("abc");
//	vector<int> v4(s1.begin(), s1.end());
//	for (auto e : v4)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

int main()
{
	vector<int> v1;
	for (int i = 0; i < 1; i++)
	{
		v1.push_back(i);
	}
	cout << v1.size() << " " << v1.capacity() << endl;
	v1.resize(100);
	cout << v1.size() << " " << v1.capacity() << endl;

	return 0;
}