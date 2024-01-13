#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1("abc de f");
//	cout << s1 << endl;
//	//所有空格替换为%
//	size_t pos = s1.find(' ');
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "%");//但是效率非常低
//		pos = s1.find(' ', pos + 1);
//	}
//	cout << s1 << endl;
//
//	string s2("abc de f");
//	cout << s2 << endl;
//	string s3;
//	for (auto e : s2)
//	{
//		if (e == ' ')
//		{
//			s3 += '%';
//		}
//		else
//		{
//			s3 += e;
//		}
//	}
//	cout << s3 << endl;
//	//如果想要返回s2本身
//	s2.swap(s3);//这是string里的swap，不是库函数里的（这个效率更好）
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("Test.tex");
//	//分离后缀
//	size_t pos = s1.rfind('.');
//	if (pos != string::npos)
//	{
//		string ret = s1.substr(pos);
//		cout << ret << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	string s1 = "Test.tex";//先把字符串隐式转换为const string & 怎么知道能的。看看下面这个
//
//	const string& a = "abcd";
//	
//
//	return 0;
//}

//int main()
//{
//	string s1 = "abc";
//	cout << s1 << endl;
//	s1.insert(0, "111");//0前面不就相当于头插嘛
//	cout << s1 << endl;
//	s1.insert(0, 2, 'x');
//	cout << s1 << endl;
//	s1.erase(0, 5);//从0处，删除5个
//	cout << s1 << endl;
//	return 0;
//}

int main()
{
	string s1("test.c");
	//得到文件后缀
	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		string ret1 = s1.substr(pos1);
		cout << ret1 << endl;
	}
	//如果文件名含有  . 怎么办
	string s2("te.st.c");
	size_t pos2 = s2.rfind('.');
	if (pos2 != string::npos)
	{
		string ret2 = s2.substr(pos2);
		cout << ret2 << endl;
	}
	return 0;
}