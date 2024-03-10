#pragma once

namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode* _left;//左指针
		BSTreeNode* _right;//右指针
		K _key;//存数据的

		BSTreeNode(const K& key)//构造函数
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree() = default;//强制生成默认构造函数

		BSTree(const BSTree<K>& t)//拷贝构造函数
		{
			_root = copy(_root);
		}

		Node* copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;

			Node* newnode = new Node(root->_key);
			if (root->_left)
			{
				newnode->_left = copy(root->_left);
			}
			if (root->_right)
			{
				newnode->_right = copy(root->_right);
			}
			return newnode;
		}

		~BSTree()//析构函数
		{
			Destory(_root);
		}

		void Destory(Node* root)//走个后序
		{
			if (root == nullptr)
				return;

			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}

		////////////////////
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}
			else
			{
				Node* cur = _root;
				Node* parent = nullptr;//这里存父亲节点，方便后续链接上
				while (cur)
				{
					if (key < cur->_key)
					{
						parent = cur;
						cur = cur->_left;
					}
					else if (key > cur->_key)
					{
						parent = cur;
						cur = cur->_right;
					}
					else
					{
						return false;//搜索二叉树里不能有相同 
					}
				}//出来后cur是nullptr,parent是叶子节点
				cur = new Node(key);//重新利用
				if (parent->_key < key)
				{
					parent->_right = cur;
				}
				else
				{
					parent->_left = cur;
				}

				return true;
			}
		}

		bool Find(const K& key)
		{
			Node* cur = _root;//创建临时节点
			while (cur)
			{
				if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else
				{
					return true;//这是找到啦
				}
			}
			return false;//没找到才会出循环
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)//先找到在哪里删除
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else//进来就说明找到啦，就是现在的cur
				{
					if (cur->_left == nullptr)//左为空，就把右给父亲节点（为空也无妨）
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_right)//cur在parent右，那就接到右侧
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_right;
							}
						}

						delete cur;
						return true;
					}
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_right)//cur在parent右，那就接到右侧
							{
								parent->_right = cur->_left;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}

						delete cur;
						return true;
					}
					else//左右都不是空，使用替换法，这里用右子树最小来换
					{
						Node* rightMinParent = cur;//右子树最小的父亲节点
						Node* rightMin = cur->_right;//右子树最小的节点

						while (rightMin->_left)//开始找
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}

						cur->_key = rightMin->_key;//把值一给，现在删rightMin就行了

						if (rightMin == rightMinParent->_left)
							rightMinParent->_left = rightMin->_right;
						else
							rightMinParent->_right = rightMin->_right;

						delete rightMin;
						return true;
					}
				}
			}
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		bool InsertR(const K& key)//难点在于，如何与父亲节点进行链接
		{
			return _InsertR(_root, key);
		}

		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}

	private:
		bool _EraseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;//说明没找到，就返回空
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else//找到啦
			{
				Node* del = root;//保存一下，过会要delete的

				//这里便是引用开始发挥的作用，可以直接进行链接
				if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else//还是使用替换法，不过这次，直接交换后，再去右子树里递归
				{
					Node* rightMin = root->_right;
					while (rightMin->_left)
					{
						rightMin = rightMin->_left;
					}

					std::swap(root->_key, rightMin->_key);

					return _EraseR(root->_right, key);
				}

				delete del;
				return true;
			}
		}

		bool InsertR(Node*& root,const K& key)//为了解决这个问题，我们用&引用来解决
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}

			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}

		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)//到最后没找到
			{
				return false;
			}

			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;
			}
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		Node* _root = nullptr;//头结点
	};
}