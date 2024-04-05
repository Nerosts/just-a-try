#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include<assert.h>
using namespace std;

//int minDeletionsToFormChain(int N, vector<int>& nums) 
//{
//    vector<int> dp(N, 1);
//
//    for (int i = 1; i < N; i++) 
//    {
//        if (to_string(nums[i])[0] == to_string(nums[i - 1]).back()) 
//        {
//            dp[i] = dp[i - 1] + 1;
//        }
//        else 
//        {
//            dp[i] = dp[i - 1];
//        }
//    }
//    return N - dp.back();
//}

//int main() 
//{
//    int N;
//    cin >> N;
//
//    vector<int> nums(N);
//    for (int i = 0; i < N; i++) 
//    {
//        cin >> nums[i];
//    }
//    int a = INT_MAX;
//    int result = minDeletionsToFormChain(N, nums);
//    cout << result << endl;
//
//    return 0;
//}

namespace mystring
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// �������� -- ��ֵ
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// �ƶ����� -- ��ֵ(����ֵ)
		string(string&& s)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// ������ֵ
		// s2 = tmp
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ�����" << endl;
			swap(s);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // �������������ʶ��\0
	};

	mystring::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		mystring::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;
			str += ('0' + x);
		}
		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

int main()
{
	
	mystring::string str = mystring::to_string(123);
	return 0;
}
