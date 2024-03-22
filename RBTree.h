#pragma once

enum Colour//使用枚举来定义，后面模拟哈希时也会用到类似的
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;//左节点
	RBTreeNode<K, V>* _right;//右节点
	RBTreeNode<K, V>* _parent;//父亲节点
	Colour _col;//颜色，红和黑嘛
	pair<K,V> _kv;//节点里存pair

	RBTreeNode(const pair<K, V>& kv)//都直接在初始化列表里初始化了
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)//这里新插入的节点一定要是红色，黑色的话会直接破坏规则
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;//名字太长了，叫Node也更好理解
public:
	bool Insert(const pair<K,V> kv)
	{
		if (_root == nullptr)//如果为空，直接更换新节点
		{
			_root = new Node(kv);
			_root->_col = BLACK;//注意默认是红，这里改成黑
			return true;
		}

		Node* parent = nullptr;//存一下，新根才能链接
		Node* cur = _root;
		while (cur)//开始找插入位置
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;//不能有相等的
			}
		}

		cur = new Node(kv); //这是默认红色的
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;//新节点链接成功了

		while (parent != nullptr 
			&& parent->_col == RED)//父亲节点存在且是红进来，黑的直接满足不用调整
		{
			Node* grandfather = parent->_parent;
			//接下来分两种：parent是grandfather左或者右
			if (parent == grandfather->_left)//左
			{
				Node* uncle = grandfather->_right;
				//情况一：叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					//先变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//继续往上走
					cur = grandfather;
					parent = cur->_parent;
				}
				else//情况二：叔叔不存在或者存在且为黑
				{
					if (cur == parent->_left)//cur在parent左，单旋
					{
						//       g
						//    p    u
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//cur在parent右，双旋
					{
						//       g
						//    p     u
						//      c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
				//情况二一旦旋转完了，不用向上了
				break;
			}
			else//parent是grandfather右
			{
				Node* uncle = grandfather->_left;
				// 情况一：叔叔存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else// 情况二：叔叔不存在或者存在且为黑
				{
					// 旋转+变色
					//      g
					//   u     p
					//            c
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//		g
						//   u     p
						//      c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
				break;
			}
		}
		_root->_col = BLACK;//最后直接改根节点，不用再具体考虑
		return true;
	}
	void RotateL(Node* parent)//左旋
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subR;
			}
			else
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}
	}

	void RotateR(Node* parent)//右旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* ppnode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = subL;
			}
			else
			{
				ppnode->_right = subL;
			}
			subL->_parent = ppnode;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_kv.first<< endl;
		_InOrder(root->_right);
	}

	bool IsBalance()
	{
		if (_root->_col == RED)
		{
			return false;
		}
		//这里我们先算一条路径的黑色节点数量，作为参考
		int ref = 0;
		Node* cur = _root;
		while (cur)
		{
			if(cur->_col==BLACK)
				ref++;
			cur = cur->_left;//就求最左路径
		}
		return Check(_root, 0, ref);
	}

	bool Check(Node* cur, int blackNum, int ref)
	{
		if (cur == nullptr)//==nullptr 说明一条路径走完了
		{
			if (blackNum != ref)
			{
				cout << "黑色节点的数量不相等" << endl;
				return false;
			}
			return true;
		}

		//这里开始检查没有连续的红，就看每个cur节点和他的父亲就行
		if (cur->_col == RED && cur->_parent->_col == RED)
		{
			cout << cur->_kv.first << "存在连续的红色节点" << endl;
			return false;
		}

		if (cur->_col == BLACK)
		{
			blackNum++;
		}

		return Check(cur->_left, blackNum, ref)
			&& Check(cur->_right, blackNum, ref);//递归进去找
	}

private:
	Node* _root = nullptr;//给上缺省值
};

void TestRBTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15};
	RBTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}
	t.InOrder();
	cout << t.IsBalance() << endl;
}


