#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//int main()
//{
//	string s1("abc de f");
//	cout << s1 << endl;
//	//���пո��滻Ϊ%
//	size_t pos = s1.find(' ');
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "%");//����Ч�ʷǳ���
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
//	//�����Ҫ����s2����
//	s2.swap(s3);//����string���swap�����ǿ⺯����ģ����Ч�ʸ��ã�
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("Test.tex");
//	//�����׺
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
//	string s1 = "Test.tex";//�Ȱ��ַ�����ʽת��Ϊconst string & ��ô֪���ܵġ������������
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
//	s1.insert(0, "111");//0ǰ�治���൱��ͷ����
//	cout << s1 << endl;
//	s1.insert(0, 2, 'x');
//	cout << s1 << endl;
//	s1.erase(0, 5);//��0����ɾ��5��
//	cout << s1 << endl;
//	return 0;
//}

int main()
{
	string s1("test.c");
	//�õ��ļ���׺
	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		string ret1 = s1.substr(pos1);
		cout << ret1 << endl;
	}
	//����ļ�������  . ��ô��
	string s2("te.st.c");
	size_t pos2 = s2.rfind('.');
	if (pos2 != string::npos)
	{
		string ret2 = s2.substr(pos2);
		cout << ret2 << endl;
	}
	return 0;
}