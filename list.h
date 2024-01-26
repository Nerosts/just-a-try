#pragma once
#include<assert.h>

namespace MyList
{
	template<class T>
	struct ListNode//struct 默认公有，class默认私有
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x=T())
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}
	};

	template<class T,class Ref>
	struct __list_iterator//自定义才能重载运算符啊(只是包装了一层而已)
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T> self;

		Node* _node;

		__list_iterator(Node* node)//构造函数的名称必须与类的名称相同
			//self 只是一个 typedef 的别名，用于在类内部引用当前类的类型
			//但是，在构造函数中，你仍然需要使用实际的类名称。
			:_node(node)
		{}

		self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)//后置
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		bool operator!=(const self& s)const//迭代器跟迭代器比啊
		{
			return _node != s._node;
		}

		bool operator==(const self& s)const
		{
			return _node == s._node;
		}

	};

	//template<class T>
	//struct __list_const_iterator//自定义才能重载运算符啊(只是包装了一层而已)
	//{
	//	typedef ListNode<T> Node;
	//	typedef __list_const_iterator<T> self;

	//	Node* _node;

	//	__list_const_iterator(Node* node)//构造函数的名称必须与类的名称相同
	//		//self 只是一个 typedef 的别名，用于在类内部引用当前类的类型
	//		//但是，在构造函数中，你仍然需要使用实际的类名称。
	//		:_node(node)
	//	{}

	//	self operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	self operator++(int)//后置
	//	{
	//		self tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	self operator--()
	//	{
	//		_node = _node->_prev;
	//		return *this;
	//	}

	//	const T& operator*()
	//	{
	//		return _node->_data;
	//	}

	//	bool operator!=(const self& s)const//迭代器跟迭代器比啊
	//	{
	//		return _node != s._node;
	//	}

	//	bool operator==(const self& s)const
	//	{
	//		return _node == s._node;
	//	}

	//};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;//默认是private 不给外面用
	public:
		typedef __list_iterator<T,T&> iterator;
		typedef __list_iterator<T,const T&> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next;也行，有单参数的构造函数支持隐式类型转换
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return iterator(_head->_next);
			//return _head->_next;也行，有单参数的构造函数支持隐式类型转换
		}

		const_iterator end()const
		{
			return iterator(_head);
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//list(const list& copy)
		//{
		//	_head = new Node;
		//	_head->_next = _head;
		//	_head->_prev = _head;

		//	iterator it = copy.begin();
		//	while (it != copy.end())
		//	{
		//		push_back(*it);
		//		it++;
		//	}
		//}

		list(list<T>& copy)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			iterator it = copy.begin();
			while (it != copy.end())
			{
				push_back(*it);
				it++;
			}
		}

		void swap(list<T>& other)
		{
			std::swap(_head, other._head);
		}

		list<T>& operator=(list<T>& other)
		{
			clear();
			swap(other);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//void push_back(const T& x)
		//{
		//	Node* newnode = new Node(x);
		//	Node* tail = _head->_prev;

		//	newnode->_next = _head;
		//	newnode->_prev = tail;
		//	tail->_next = newnode;
		//	_head->_prev = newnode;
		//}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		iterator insert(iterator pos, const T& x)//不会失效：没有扩容、没有移动数据（memmove)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			newnode->_next = cur;
			cur->_prev = newnode;
			newnode->_prev = prev;
			prev->_next = newnode;

			return newnode;
		}

		iterator erase(iterator pos)//有可能失效，delete cur了，pos不能用了
		{
			assert(pos != _head);

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return next;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

	private:
		Node* _head;
	};

	void test1()
	{
		const list<int> l(5,1);

		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
}