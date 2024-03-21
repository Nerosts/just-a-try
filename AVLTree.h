#pragma once

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;//父亲节点
	int _bf; // balance factor 平衡因子
	pair<K, V> _kv;//每个节点里存一个pair

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)//都直接在初始化列表里初始化了
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;//名字太长了，叫Node也更好理解
public:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;//要成为根的
		Node* subRL = subR->_left;//要成为30的右子树

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;//存一下，新根才能链接
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)//parent在pp的左，那我新的跟subR也要左
			{
				ppnode->_left = subR;
			}
			else//同理
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}

		//更新平衡因子
		parent->_bf = 0;
		subR->_bf = 0;
	}
	void RotateR(Node* parent)
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

		subL->_bf = 0;
		parent->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;//存一下，后面要更新bf

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == 1)
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}
	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		subRL->_bf = 0;
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else
		{
			parent->_bf = 0;
			subR->_bf = 0;
		}
	}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)//如果是空树
		{
			_root = new Node(kv);
			return true;//插入成功
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)//这里开始找位置
		{
			if (kv.first < cur->_kv.first)//小于往左走
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;//不能有相等的
			}
		}
		//开始把新节点链接上
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;

		//更新平衡因子
		while (parent != nullptr)//cur到跟节点停下
		{
			if (cur == parent->_left)//在左就--
			{
				parent->_bf--;
			}
			else//在右++
			{
				parent->_bf++;
			}
			//开始检查父亲节点的情况
			if (parent->_bf == 0)
			{
				break;//直接停止
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;//向上走
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//破坏了规则了，开始旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else
				{
					RotateRL(parent);
				}

				break;//调整完后就平衡了，也不用向上，直接出去
			}
			else
			{
				// 会到这说明插入之前AVL树就有问题
				assert(false);
			}
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
		cout << root->_kv.first << "[" << root->_bf << "]" << endl;
		_InOrder(root->_right);
	}

	int Height()
	{
		_Height(_root);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int right = _Height(root->_right);
		int left = _Height(root->_left);
		return right > left ? right + 1 : left + 1;
	}
	bool IsBalance()
	{
		int height = 0;
		return _IsBlance(_root, height);
	}
	bool _IsBlance(Node* root, int& h)
	{
		if (root == nullptr)
		{
			h = 0;
			return true;
		}

		int leftHeight = 0, rightHeight = 0;
		if (!_IsBlance(root->_left, leftHeight)
			|| !_IsBlance(root->_right, rightHeight))
		{
			return false;
		}

		if (abs(rightHeight - leftHeight) >= 2)
		{
			cout << root->_kv.first << "不平衡" << endl;
			return false;
		}
		h= leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return true;
	}

private:
	Node* _root = nullptr;//给上缺省值
};

void TestAVLTree1()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
		cout << e << "->" << t.IsBalance() << endl;
	}

	t.InOrder();
	cout << t.IsBalance() << endl;
}
