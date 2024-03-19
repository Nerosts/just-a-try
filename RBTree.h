#pragma once
#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T,A,B> Self;

	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{}

	A operator*()
	{
		return _node->_data;
	}
	B operator->()
	{
		return &(_node->_data);
	}
	Self& operator++()
	{
		if (_node->_right)
		{
			Node* subR = _node->_right;
			while (subR->_left)
			{
				subR = subR->_left;
			}
			_node = subR;
		}
		else//右不存在或者
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent != nullptr && cur == parent->_right)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self& operator++(int)
	{
		Self cur = *this;
		++(*this);
		return cur;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			Node* subL = _node->_left;
			while (subL->_right)
			{
				subL = subL->_right;
			}
			_node = subL;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent != nullptr && parent->_left == cur)
			{
				cur = cur->_parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
};

template<class K, class T , class KeyOfT>
class RBTree
{
	typedef RBTreeNode<T> Node;

	typedef RBTreeIterator<T,T&,T*> iterator;
	typedef RBTreeIterator<T,const T&,const T*> const_iterator;
public:
	const_iterator begin() const 
	{
		return begin();
	}

	iterator begin()
	{
		Node* searchL = _root;
		while (searchL&&searchL->_left)//自己不为空
		{
			searchL = searchL->_left;
		}
		return iterator(searchL);
	}
	iterator end()
	{
		return iterator(nullptr);
	}

	iterator Find(const K& key)
	{
		if (_root == nullptr)
		{
			return end();
		}
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else
			{
				return iteratot(cur);
			}
		}
		return end();
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* grandfather = parent->_parent;//此时g的左或者右还是指向parent的
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parent == grandfather->_left)
			{
				grandfather->_left = subR;
			}
			else
			{
				grandfather->_right = subR;
			}
			subR->_parent = grandfather;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* grandfather = parent->_parent;//此时g的左或者右还是指向parent的
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == grandfather->_left)
			{
				grandfather->_left = subL;
			}
			else
			{
				grandfather->_right = subL;
			}
			subL->_parent = grandfather;
		}
	}

	pair<iterator,bool> Insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root),true);
		}
		KeyOfT kot;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return make_pair(iterator(cur), false);//有相同的了
			}
		}
		cur = new Node(kv);
		Node* newnode = cur;

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;//链接完毕

		while (parent != nullptr && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)//uncle在右
			{
				Node* uncle = grandfather->_right;
				// 情况一：叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					//变色
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;
					//向上走
					cur = grandfather;
					parent = cur->_parent;
				}//情况一
				else//情况二：叔叔不存在或者存在且为黑
				{
					if (cur == parent->_left)//左的左，右单旋
					{
						//       g
						//    p    u
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//左的右，先左再右
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;//旋转完后，就已经不需要再向上了
				}

			}
			else//uncle在左
			{
				Node* uncle = grandfather->_left;
				if (uncle != nullptr && uncle->_col == RED)
				{
					//变色
					uncle->_col = parent->_col = BLACK;
					grandfather->_col = RED;
					//向上走
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)//右的右，左单旋
					{
						//       g
						//    u    p
						//            c
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//左的右，先右再左
					{
						//       g
						//    u     p
						//        c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;//旋转完后，就已经不需要再向上了
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(newnode), true);
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalance()
	{
		if (_root && _root->_col == RED)
		{
			return false;
		}
		int reference = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				reference++;
			cur = cur->_left;
		}
		return check(_root, 0, reference);
	}
	bool check(Node* cur, int BlackNum, int reference)
	{
		if (cur == nullptr)
		{
			if (BlackNum != reference)
			{
				return false;
			}
			return true;
		}

		if (cur->_col == RED && cur->_parent->_col == RED)
		{
			return false;
		}

		if (cur->_col == BLACK)
		{
			BlackNum++;
		}

		return check(cur->_left, BlackNum, reference) &&
			check(cur->_right, BlackNum, reference)
	}

private:
	Node* _root = nullptr;
};