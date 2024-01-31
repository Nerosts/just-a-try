#pragma once

template <class iterator,class Ref,class Pre>
struct reserve_iterator
{
	typedef reserve_iterator<iterator, Ref, Pre> self;

	iterator _it;

	reserve_iterator(iterator it)
		:_it(it)  
	{}

	self& operator++()
	{
		--_it;
		return *this;
	}
	self operator++(int)
	{
		self tmp = *this;
		--_it;
		return tmp;
	}

	self& operator--()
	{
		++_it;
		return *this;
	}
	self operator--(int)
	{
		self tmp = *this;
		++_it;
		return tmp;
	}

	Ref operator*()
	{
		iterator tmp = _it;
		--tmp;
		return *tmp;
	}

	Pre operator->()
	{
		return &(operator*());
	}

	bool operator!=(const self& s)
	{
		return _it != s._it;
	}
	bool operator==(const self& s)
	{
		return _it == s._it;
	}

};