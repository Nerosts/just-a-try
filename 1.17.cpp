#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace Str
{
	class string
	{
	public:
		//�ֿ�
		//string()//�ղ�
		//{
		//	_size = 0;
		//	_capacity = 0;
		//	_str = new char[1];
		//	_str[0] = '\0';
		//}
		//string(const char* str)
		//{
		//	_size = strlen(str);
		//	_capacity = _size;//��Ч�ַ��ռ�
		//	_str = new char[_size + 1];//+1���� \0
		//	strcpy(_str, str);//����һ��
		//}
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()//���һ���ĺ�һ��
		{
			return _str + _size;
		}

		const_iterator begin()const
		{
			return _str;
		}

		const_iterator end()const
		{
			return _str + _size;
		}


		string(const char* str = "")//������
			:_size(0)
			,_capacity(0)
			,_str(nullptr)//��ʼ��һ�£���ֹ�������Լ�����ʼ�������ֵ
		{
			_size = strlen(str);
			_capacity = _size;//��Ч�ַ��ռ�
			_str = new char[_size + 1];//+1���� \0
			strcpy(_str, str);//����һ��
		}

		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	strcpy(_str, s._str);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}

		string(const string& s)
		{
			string tmp(s._str);
			swap(tmp);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		const char* c_str()const
		{
			return _str;//��СȨ��
		}

		void reserve(size_t newcapacity)
		{
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 1];//���1�����Է�ûλ�ô�\0
				strcpy(str, _str);
				delete[] _str;
				_str = str;//ָ���µ�
				_capacity = newcapacity;
			}
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';//����0�Ļ���cout<<s.c_str()��Ȼ����
		}

		void push_back(char ar)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			_str[_size] = ar;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* arr)
		{
			int len = strlen(arr);
			if (_size + len > _capacity)//����Ҳû�£�reserve����+1��
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, arr);
			_size += len;
		}

		void insert(size_t pos, char ar)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			//pos��ʼ��ȫ��������һ��
			int end = _size;// \0Ҳ����
			while (end >= (int)pos)//posһ��Ϊsize_t���ͣ���ʱ��end�������������з����������ͻᱻ����Ϊ�޷����������͡���
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[end + 1] = ar;
			_size++;

			//����
			//int end = _size + 1;
			//while (end > pos)
			//{
			//	_str[end] = _str[end - 1];
			//	--end;
			//}
			//_str[pos] = ar;
			//++_size;
		}

		void insert(size_t pos, const char* arr)
		{
			int len = strlen(arr);
			if (_size + len > _capacity)//����Ҳû�£�reserve����+1��
			{
				reserve(_size + len);
			}
			int end = _size + len;
			while (end > pos)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, arr, len);//����\0
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				int start = pos;
				while (start <= pos + len - 1)
				{
					_str[start] = _str[start + len];
					start++;
				}
				_size -= len;
			}
		}

		void swap(string& s)//����������ֱ�ӻ�����Ҫ������ĳ�Ա����
		{
			//std::swap(_str, s._str);
			//std::swap(_size, s._size);
			//std::swap(_capacity, s._capacity);
			string s1 = *this;
			*this = s;
			s = s1;
		}

		size_t find(char ar, size_t pos = 0)//���ַ�
		{
			for (int i = pos; i < _size; i++)
			{
				if (ar == _str[i])
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(char* arr, size_t pos = 0)//���ַ���
		{
			char* ret = strstr(_str, arr);
			if (ret == nullptr)
			{
				return npos;
			}
			else
			{
				return ret - _str;//0  1  2  3 �����2���Ǿ���2-0
			}
		}

		string substr(size_t pos, size_t len = npos)
		{
			size_t end = pos + len;
			if (len == npos || pos + len >= _size)
			{
				end = _size;// \0λ��
			}
			//��ʼpos��end��ֵ���µ�һ���ռ䣬�ٷ���
			string s;
			s.reserve(end - pos);//�����_size-pos,��Ȼ�Ǹպã�����reserve��+1����\0��
			for (int i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}

		string& operator+=(char ar)
		{
			push_back(ar);
			return *this;
		}

		string& operator+=(const char* arr)//���ض������ã������Ƕ�������ַ�����
		{
			append(arr);
			return *this;
		}

		const char operator[](int pos)const//��������һ��const���ܸ�
		{
			assert(pos <= _size);
			return _str[pos];
		}

		char operator[](int pos)//��const�ܸ�
		{
			assert(pos <= _size);
			return _str[pos];
		}

		//string& operator=(const string& s)//s1=s2 �¿ռ䣬���ƺ�s1�ͷţ�ָ���µ�
		//{
		//	if (this != &s)
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		strcpy(tmp, s._str);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}

		string& operator=(string s)//s1=s2 �¿ռ䣬���ƺ�s1�ͷţ�ָ���µ�
		{
			if (this != &s)
			{
				swap(s);//���ó���������͵�����������������
			}
			return *this;
		}

	private:
		char* _str;
		int _size;
		int _capacity;//���������Ǳ�����ڳ�ʼ���б��

		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, string& s)
	{
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)//cin���� ��\n
	{
		char ch = in.get();
		s.clear();
		while (ch != ' ' && ch != '\n')
		{
			//�����һ��
			s += ch;
			ch = in.get();
		}
		return in;
	}

	//istream& operator>>(istream& in, string& s)//cin���� ��\n   �µ�
	//{
	//	char ch = in.get();
	//	s.clear();
	//	char buffe[128];
	//	int i = 0;
	//	while (ch != ' ' || ch != '\n')
	//	{
	//		buffe[i++] = ch;
	//		if (i == 127)
	//		{
	//			buffe[i] = '\0';
	//			s += buffe;
	//			i = 0;
	//		}
	//		ch = in.get();
	//	}
	//	if (i > 0)
	//	{
	//		buffe[i] = '\0';
	//		s += buffe;
	//	}
	//	return in;
	//}

	void test1()
	{
		string s1("abc");//�ǳ����ַ���
		cout << s1.c_str() << endl;
		s1 += 'x';
		cout << s1.c_str() << endl;
		s1.insert(0, 'a');
		cout << s1.c_str() << endl;

		string s2("ABC");//�����ַ���
		s1.swap(s2);
		cout << s2 << endl;
	}

	void test2()
	{
		string s1("abc");//�ǳ����ַ���
		cout << s1.c_str() << endl;
		cout << s1.find('b');
	}

	void test3()//find+substr
	{
		string s1("test.cpp");
		size_t pos = s1.find('.');
		string ret = s1.substr(pos);
		cout << ret.c_str();
	}

	void test4()
	{
		string s1;
		cin >> s1;
		cout << s1;
	}
}

