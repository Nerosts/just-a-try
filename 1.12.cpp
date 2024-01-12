#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
using namespace std;
//int main()
//{
//	string s1;
//	string s2("abcd");
//	string s3(5, 'c');
//	string s4(s2);
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	return 0;
//}

//int main()
//{
//	string s1 = "abcde";//拷贝构造
//	for (int i = 0; i < s1.size(); ++i)//进行遍历
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	//进行更改
//	s1[0] = '1';
//	cout << s1;
//	return 0;
//}

//int main()
//{
//	string s1 = "abcde";//拷贝构造
//	for (auto e: s1)//只能遍历
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : s1)//想要改变，加&
//	{
//		e = 'a';
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s1 = "abcde";//拷贝构造
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//开始翻转
//	it = s1.begin();
//	while (it != s1.end())//再次打印
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	list<double> l1;//定义一个链表来说明，迭代器两个特点
//	l1.push_back(1.1);
//	l1.push_back(2.2);
//	l1.push_back(3.3);	
//	list<double>::iterator lit=l1.begin();
//	while (lit != l1.end())
//	{
//		cout << *lit << " ";
//		lit++;
//	}
//	cout << endl;
//	reverse(l1.begin(), l1.end());
//	lit = l1.begin();
//	while (lit != l1.end())
//	{
//		cout << *lit << " ";
//		lit++;
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s = "abcde";
//	const string cs = "abc";
//	string::iterator it = s.begin();//会去找最适合的
//	string::const_iterator cit = cs.begin();//用string::iterator cit = cs.begin();会报错
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("abcde");
//	cout << s1.max_size() << endl;
//	cout << s2.max_size() << endl;//跟有无值没有关系，返回整形最大值的一半：2的31次方
//	//不同编译器下都有可能不一样（没有参考意义）不一定真能开这么大
//	//实践当中没有参考意义和使用价值
//
//	cout << s2.capacity() << endl;
//	for (int i = 0; i < 50; i++)
//	{
//		s2.push_back('a');
//		
//	}
//	return 0;
//}

//增删查改 append           []、[] 迭代器
//int main()
//{
//	string s1 = "abcde";//隐式转换后构造，再拷贝构造
//	const string& s2 = "1111";//string& append (const string& str);   "1111"可以隐式转换为const string&
//	s1.append(s2);
//	s1.append("jsaod");//string& append (const string& str);  
//
//	//但是+=最常用
//	s1 += s2;
//	s1 += "aaa";
//	return 0;
//}

//void fun(char ar)
//{
//	cout << ar;
//}
//
//int main()
//{
//	fun('a' + 2);
//	return 0;
//}

//int main()
//{
//	string s1("abcde");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//	return 0;
//}

int main()
{
	string s1("abcde");
	s1 += "111";
	cout << s1 << endl;
	return 0;
}

