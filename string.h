#pragma once
#include<string.h>

namespace MyString
{
	class string
	{
	public:
		//构造函数
		//string()//空参的
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
		//	_str = new char[_size + 1];//加一是给 \0
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
			_str = new char[_size + 1];//加一是给 \0
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}

		string& operator=(const string& s)//创建好新的空间（复制跟赋值）。再清理旧空间指向新的
		{
			char* tmp = new char[s._capacity+1];//创建好新空间
			strcpy(tmp, s._str);
			_size = s._size;
			_capacity = s._capacity;//复制跟赋值
			delete[] _str;
			_str = tmp;//清理，指向新的
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
			std::swap(*this, s);//使用库里的swap
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
				_str = tmp;//指向新的
			}
		}

		void push_back(char c)
		{
			if (_size == _capacity)
			{
				int newCapacity = _capacity == 0 ? 4 : 2 * _capacity;//有可能是空参构造
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

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const//默认从0开始找
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

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			char* ret = strstr(_str, s);//返回第一次出现的位置
			if (ret == nullptr)//没找到
			{
				return npos;
			}
			return ret - _str ;
		}

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			if (_size = _capacity)//先看空间够不够
			{
				int newcapacity = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newcapacity);
			}
			//先向后移一格
			int end = _size;// \0也往后
			while (end >= (int)pos)//pos一般为size_t类型，此时，end会整型提升（有符号整数类型会被提升为无符号整数类型。）
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
			//先向后移len个格
			int end = _size;// \0也往后
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			strncpy(_str + pos, str,len);
			_size += len;
			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
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
			//开始pos到end赋值到新的一个空间，再返回
			string s;
			reserve(end - pos);
			for (int i = pos; i < end; i++)
			{
				s += _str[i];
			}
			return s;
		}

	private:
		int _size;//有效字符的数量
		int _capacity;//开的空间大小
		char* _str;//没有设计成模版，就直接用char数组了
		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, string& s)//不需要放在类内，不需要是友元（不用访问成员）
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
		char ch = in.get();//使用cin拿不到空格和换行，二者其实还是字符，就用这个get
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}


}
