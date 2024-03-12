#pragma once

template<class K, class V>//节点
class AVLTreeNode
{
public:
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode<K, V>* parent;
	int _bf//balance factor
	pair<K, V> _kv;

	AVLTreeNode(pair<K, V>& kv)
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:

	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* prev = nullptr;//用来连接
		Node* cur = _root;
		while (cur)
		{
			if (kv.first < cur->_kv.first)
			{
				prev = cur;
				cur = cur->left;
			}
			else if (kv.first < cur->_kv.first)
			{
				prev = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}

			cur = new Node(kv);
			if (kv.first < prev->_kv.first)
			{
				prev->left = cur;
			}
			else
			{
				prev->right = cur;
			}
			cur->parent = prev;
			//链接好了，现在处理_bf
			while (prev)
			{
				if (cur == prev->left)
				{
					prev->_bf--;
				}
				else
				{
					prev->_bf++;
				}

				if (prev->_bf == 0)
				{
					//停止
					break;
				}
				else if (prev->_bf == 1 || prev->_bf == -1)
				{
					//上赶
					cur = prev;
					prev = prev->parent;
				}
				else if (prev->_bf == 2 || prev->_bf == -2)
				{
					//旋转
					if (prev->_bf == 2 && cur->_bf == 1)
					{
						RotateL(prev);
					}
					else if (prev->_bf == -2 && cur->_bf == -1)
					{
						RotateR(prev);
					}
					else if (prev->_bf == -2 && cur->_bf == 1)
					{
						RotateLR(prev);//先左旋再右旋
					}
					else if (prev->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(prev);//先you旋再left旋
					}
					else
					{
						assert(false);//正常的话不会进来的
					}
					break;
				}
				else
				{
					assert(false);//到这说明之前就有错了
				}
				
			}
		}
	}
	void RotateL(Node* parent)//左旋转
	{
		Node* subR = parent->right;//右子树根
		Node* subRL = subR->left;//右子树的左侧
		Node* ppNode = parent->parent;//有可能是一个子树，或者独立的树

		parent->right = subRL;
		if (subRL)//不是空才行
		{
			subRL->parent = parent;
		}

		subR->left = parent;
		parent->parent = subR;
		if (_root == parent)
		{
			_root = subR;
			subR->parent = nullptr;
		}
		else//是子树
		{
			if (ppNode->left == parent)
			{
				ppNode->left = subR;
			}
			else
			{
				ppNode->right = subR;
			}
			subR->parent = ppNode;
		}
		parent->_bf = subR->_bf = 0;
	}
	void RotateR(Node* parent)//右旋转
	{
		Node* subL = parent->left;//右子树根
		Node* subLR = subR->right;//右子树的左侧
		Node* ppNode = parent->parent;//有可能是一个子树，或者独立的树

		parent->right = subLR;
		if (subLR)//不是空才行
		{
			subLR->parent = parent;
		}

		subL->right = parent;
		parent->parent = subL;
		if (_root == parent)
		{
			_root = subL;
			subL->parent = nullptr;
		}
		else//是子树
		{
			if (ppNode->left == parent)
			{
				ppNode->left = subL;
			}
			else
			{
				ppNode->right = subL;
			}
			subL->parent = ppNode;
		}
		parent->_bf = subL->_bf = 0;
	}
	void RotateLR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;
		int bf = subLR->_bf;//都先储存一下

		RotateL(parent->left);
		RotateR(parent);

		//开始更新_bf
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
		Node* subR = parent->right;
		Node* subRL = subR->left;
		int bf = subRL->_bf;//存一下

		RotateR(subR);
		RotateL(parent);

		//开始更新_bf
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

private:
	Node* _root = nullptr;
};