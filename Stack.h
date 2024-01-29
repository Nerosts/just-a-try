#pragma once

namespace MyStack
{
	template<class T, class Container=deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_c.push_back(x);
		}

		void pop()
		{
			_c.pop_back();
		}

		T& top()
		{
			return _c.back();
		}

		size_t size()
		{
			return _c.size();
		}

		bool empty()
		{
			return _c.empty();
		}
	private:
		Container _c;
	};
}
