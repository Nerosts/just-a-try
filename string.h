#pragma once
#include<string.h>

namespace MyString
{
	class string
	{
	public:
		//���캯��
		//string()//�ղε�
		//{
		//	_size = 0;
		//	_capacity = 0;
		//	_str = new char[1];
		//	_str[0] = '\0';
		//}
		//string(const char* str)
		//{
		//	_size = strlen(str);
		//	_capacity = _size;
		//	_str = new char[_size + 1];//��һ�Ǹ� \0
		//	strcpy(_str, str);
		//}
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
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


		string(const char* str="")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];//��һ�Ǹ� \0
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)//�������µĿռ䣨���Ƹ���ֵ����������ɿռ�ָ���µ�
		{
			char* tmp = new char[s._capacity+1];//�������¿ռ�
			strcpy(tmp, s._str);
			_size = s._size;
			_capacity = s._capacity;//���Ƹ���ֵ
			delete[] _str;
			_str = tmp;//����ָ���µ�
			return *this;
		}


		const char* c_str()const
		{
			return _str;
		}

		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

		void swap(string& s)
		{
			std::swap(*this, s);//ʹ�ÿ����swap
		}

		char& operator[](size_t index)
		{
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			return _str[index];
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		size_t size()const
		{
			return _size;
		}

		size_t capacity()const
		{
			return _capacity;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				_capacity = n;
				char* tmp = new char[_capacity + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;//ָ���µ�
			}
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				int newCapacity = _capacity == 0 ? 4 : 2 * _capacity;//�п����ǿղι���
				reserve(newCapacity);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const//Ĭ�ϴ�0��ʼ��
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const
		{
			char* ret = strstr(_str, s);//���ص�һ�γ��ֵ�λ��
			if (ret == nullptr)//û�ҵ�
			{
				return npos;
			}
			return ret - _str ;
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c)
		{
			if (_size = _capacity)//�ȿ��ռ乻����
			{
				int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			//�������һ��
			int end = _size;// \0Ҳ����
			while (end >= (int)pos)//posһ��Ϊsize_t���ͣ���ʱ��end�������������з����������ͻᱻ����Ϊ�޷����������͡���
			{
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = c;
			_size++;
			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			int len = strlen(str);
			if (_size +len>= _capacity)
			{
				reserve(_size + len);
			}
			//�������len����
			int end = _size;// \0Ҳ����
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			strncpy(_str + pos, str,len);
			_size += len;
			return *this;
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len= npos)
		{
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				int start = pos;
				while (_size - start - len+1 > 0)
				{
					_str[start] = _str[start + len];
					start++;
				}
			}
			return *this;
		}

		string substr(size_t pos, size_t len = npos)
		{
			int end = pos + len;
			if (len == npos || pos + len >= _size)
			{
				end = _size;
			}
			//��ʼpos��end��ֵ���µ�һ���ռ䣬�ٷ���
			string s;
			reserve(end - pos);
			for (int i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}

	private:
		int _size;//��Ч�ַ�������
		int _capacity;//���Ŀռ��С
		char* _str;//û����Ƴ�ģ�棬��ֱ����char������
		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, string& s)//����Ҫ�������ڣ�����Ҫ����Ԫ�����÷��ʳ�Ա��
	{
		for (auto e : s)
		{
			out << e;
		}
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch = in.get();//ʹ��cin�ò����ո�ͻ��У�������ʵ�����ַ����������get
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}


}
