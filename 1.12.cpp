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
//	string s1 = "abcde";//��������
//	for (int i = 0; i < s1.size(); ++i)//���б���
//	{
//		cout << s1[i] << " ";
//	}
//	cout << endl;
//	//���и���
//	s1[0] = '1';
//	cout << s1;
//	return 0;
//}

//int main()
//{
//	string s1 = "abcde";//��������
//	for (auto e: s1)//ֻ�ܱ���
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : s1)//��Ҫ�ı䣬��&
//	{
//		e = 'a';
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}

//int main()
//{
//	string s1 = "abcde";//��������
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//��ʼ��ת
//	it = s1.begin();
//	while (it != s1.end())//�ٴδ�ӡ
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//
//	list<double> l1;//����һ��������˵���������������ص�
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
//	string::iterator it = s.begin();//��ȥ�����ʺϵ�
//	string::const_iterator cit = cs.begin();//��string::iterator cit = cs.begin();�ᱨ��
//	return 0;
//}

//int main()
//{
//	string s1;
//	string s2("abcde");
//	cout << s1.max_size() << endl;
//	cout << s2.max_size() << endl;//������ֵû�й�ϵ�������������ֵ��һ�룺2��31�η�
//	//��ͬ�������¶��п��ܲ�һ����û�вο����壩��һ�����ܿ���ô��
//	//ʵ������û�вο������ʹ�ü�ֵ
//
//	cout << s2.capacity() << endl;
//	for (int i = 0; i < 50; i++)
//	{
//		s2.push_back('a');
//		
//	}
//	return 0;
//}

//��ɾ��� append           []��[] ������
//int main()
//{
//	string s1 = "abcde";//��ʽת�����죬�ٿ�������
//	const string& s2 = "1111";//string& append (const string& str);   "1111"������ʽת��Ϊconst string&
//	s1.append(s2);
//	s1.append("jsaod");//string& append (const string& str);  
//
//	//����+=���
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

