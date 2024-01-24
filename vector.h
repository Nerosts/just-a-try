#pragma once
//在 C++ 中，typedef 定义的类型别名在整个类的作用域内都是可见的
//包括 public 和 private 部分。因此，即使在 public 部分定义了类型别名
//也可以在 private 部分中使用这些类型别名。


namespace MyVector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
		{}

		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}
		vector(int n, const T& val = T())//适用于  vector<int> v(5,1)
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

		//vector(const vector& v)
		//{
		//	T* tmp = new T[v.capacity()];
		//	if (v)
		//	{
		//		memccpy(tmp, v._start, sizeof(T) * (v._endOfStorage - v._start));
		//		_start = tmp;
		//		_finish = _start + (v._finish - v._start);
		//		_endOfStorage = _start + (v._endOfStorage - v._start);
		//	}
		//	else
		//	{
		//		_start = _finish = _endOfStorage = nullptr;
		//	}
		//}

		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endOfStorage(nullptr)
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
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endOfStorage = nullptr;
			}
			//是空没必要动
		}

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

		//void resize(size_t n,T& x=T())
		//{
		//	assert(n > 0);

		//	if (n > capacity())
		//	{
		//		reserve(n);
		//		for (size_t i = size(); i <= n; i++)
		//		{
		//			push_back(x);
		//		}
		//	}
		//	if (n > size())
		//	{
		//		for (size_t i = size(); i <= n; i++)
		//		{
		//			push_back(x);
		//		}
		//	}
		//	if (n < size())
		//	{
		//		for (size_t i = size(); i >= n; i--)
		//		{
		//			pop_back();
		//		}
		//	}
		//}

		void resize(size_t n,const T& x = T())
		{
			assert(n > 0);

			if (n > size())
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = x;
					_finish++;
				}
			}
			if (n < size())
			{
				_finish = _start + n;
			}
		}

		void reserve(size_t n)//扩容
		{
			if (n > capacity())
			{
				size_t old = size();//存一下，后面会改
				T* tmp = new T[n];
				if (_start != nullptr)
				{
					//memcpy(tmp, _start, sizeof(T) * old);
					for (int i = 0; i < old; i++)
					{
						tmp[i] = _start[i];//是T的=（对象对象对象）
					}
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + old;
				_endOfStorage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endOfStorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : 2 * (capacity());
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(size() > 0);
			_finish--;
		}

		iterator insert(iterator pos, const T& x)//pos之前插入
		{
			assert(pos < _finish&& pos >= _start);

			if (_finish == _endOfStorage)
			{
				size_t site = pos - _start;
				size_t newcapacity = capacity() == 0 ? 4 : 2 * (capacity());
				reserve(newcapacity);
				pos = _start + site;
			}
			
			//memmove(pos + 1, pos, sizeof(T) * (_finish - pos));浅拷贝
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;

			++_finish;
			return pos;
		}

		//void erase(iterator pos)
		//{
		//	//memmove(pos , pos+1, sizeof(T) * (_finish - pos));
		//	assert(pos < _finish&& pos >= _start);

		//	iterator start = pos + 1;
		//	while (start < _finish)
		//	{
		//		*(start - 1) = *start;
		//		start++;
		//	}
		//	_finish--;
		//}

		iterator erase(iterator pos)
		{
			//memmove(pos , pos+1, sizeof(T) * (_finish - pos));
			assert(pos < _finish&& pos >= _start);

			iterator start = pos + 1;
			while (start < _finish)
			{
				*(start - 1) = *start;
				start++;
			}
			_finish--;
			return pos;
		}

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endOfStorage - _start;
		}

		T& operator[](size_t i)
		{
			assert(i < size());

			return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());

			return _start[i];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endOfStorage;
	};

	void test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(3);
		v.push_back(3);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(3);
		v.push_back(3);

		vector<int> v2 = v;
		for (auto e : v2)
		{
			cout << e << " ";
		}
	}

	void test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(3);
		v.push_back(3);

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
		v.erase(v.begin());

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
