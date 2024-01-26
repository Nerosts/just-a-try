#pragma once
#include<assert.h>

namespace MyList
{
	template<class T>
	struct ListNode//struct Ĭ�Ϲ��У�classĬ��˽��
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
	struct __list_iterator//�Զ�����������������(ֻ�ǰ�װ��һ�����)
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T> self;

		Node* _node;

		__list_iterator(Node* node)//���캯�������Ʊ��������������ͬ
			//self ֻ��һ�� typedef �ı��������������ڲ����õ�ǰ�������
			//���ǣ��ڹ��캯���У�����Ȼ��Ҫʹ��ʵ�ʵ������ơ�
			:_node(node)
		{}

		self operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)//����
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

		bool operator!=(const self& s)const//���������������Ȱ�
		{
			return _node != s._node;
		}

		bool operator==(const self& s)const
		{
			return _node == s._node;
		}

	};

	//template<class T>
	//struct __list_const_iterator//�Զ�����������������(ֻ�ǰ�װ��һ�����)
	//{
	//	typedef ListNode<T> Node;
	//	typedef __list_const_iterator<T> self;

	//	Node* _node;

	//	__list_const_iterator(Node* node)//���캯�������Ʊ��������������ͬ
	//		//self ֻ��һ�� typedef �ı��������������ڲ����õ�ǰ�������
	//		//���ǣ��ڹ��캯���У�����Ȼ��Ҫʹ��ʵ�ʵ������ơ�
	//		:_node(node)
	//	{}

	//	self operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	self operator++(int)//����
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

	//	bool operator!=(const self& s)const//���������������Ȱ�
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
		typedef ListNode<T> Node;//Ĭ����private ����������
	public:
		typedef __list_iterator<T,T&> iterator;
		typedef __list_iterator<T,const T&> const_iterator;
		iterator begin()
		{
			return iterator(_head->_next);
			//return _head->_next;Ҳ�У��е������Ĺ��캯��֧����ʽ����ת��
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin()const
		{
			return iterator(_head->_next);
			//return _head->_next;Ҳ�У��е������Ĺ��캯��֧����ʽ����ת��
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

		iterator insert(iterator pos, const T& x)//����ʧЧ��û�����ݡ�û���ƶ����ݣ�memmove)
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

		iterator erase(iterator pos)//�п���ʧЧ��delete cur�ˣ�pos��������
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