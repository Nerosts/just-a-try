#pragma once
#include<assert.h>
namespace MyVector
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;//�ȶ���õ�����
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)//ֱ��ʹ�ó�ʼ���б�
		{}

		vector(size_t n, const T& val= T())
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())//������  vector<int> v(5,1)
		{
			resize(n, val);
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)//�����ó�ʼ���б���г�ʼ��
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}


		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				int newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		iterator insert(iterator pos, const T& x)//��posǰ����
		{
			assert(pos < _finish&& pos >= _start);

			if (_finish == _endOfStorage)
			{
				size_t site = pos - _start;
				int newcapacity = capacity() == 0 ? 2 : 2 * (capacity());
				reserve(newcapacity);

				pos = _start + site;//pos���¿ռ��λ����
			}
			iterator end = _finish - 1;
			while (end >= pos)//��ʼ���������
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)//ɾpos��
		{
			assert(pos < _finish&& pos >= _start);
			assert(size() > 0);
			//��ʼ��ǰ�ƶ�
			iterator start = pos + 1;
			while (start < _finish)
			{
				*(start - 1) = *start;
				start++;
			}
			_finish--;
			return pos;//����ɾ����λ��
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int old_size = size();//����һ�³��ȣ����������_finish�Ƶ��µ�λ��
				T* tmp = new T[n];
				if (_start != nullptr)//vector��涫����
				{
					for (size_t i = 0; i < size(); ++i)
					{
						tmp[i] = _start[i];//_start������ָ��
					}
				}
				delete[] _start;
				_start = tmp;

				_finish = _start + old_size;
				_endOfStorage = _start + n;
			}
		}

		void resize(size_t n, const T& x = T())
		{
			if (n > size())
			{
				reserve(n);//<capacity �Ļ���Ҳû�н��д���
				while (_finish != _start + n)
				{
					*_finish = x;
					++_finish; 
				}
			}
			else
			{
				_finish = _start + n;//С�ڳ���ʱ��ֱ���ƶ�finish
			}
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}


		const T& operator[](size_t i) const
		{
			assert(i < size());

			return _start[i];
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endOfStorage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};

	void test1()
	{
		vector<int> v;
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(10);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.resize(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);//β��3��
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.pop_back();//βɾһ��
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.insert(v.begin(), 0);//ͷ��һ��0
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

		v.erase(v.begin());//ͷɾ
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		//ɾ��ż��
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it=v.erase(it);//���ﲻ��ֻ��v.erase(it); ɾ����
			}
			else
			{
				it++;
			}
		}
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
