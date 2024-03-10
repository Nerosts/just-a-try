#pragma once

namespace key
{
	template<class K>
	struct BSTreeNode
	{
		BSTreeNode* _left;//��ָ��
		BSTreeNode* _right;//��ָ��
		K _key;//�����ݵ�

		BSTreeNode(const K& key)//���캯��
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
		BSTree() = default;//ǿ������Ĭ�Ϲ��캯��

		BSTree(const BSTree<K>& t)//�������캯��
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

		~BSTree()//��������
		{
			Destory(_root);
		}

		void Destory(Node* root)//�߸�����
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
				Node* parent = nullptr;//����游�׽ڵ㣬�������������
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
						return false;//�����������ﲻ������ͬ 
					}
				}//������cur��nullptr,parent��Ҷ�ӽڵ�
				cur = new Node(key);//��������
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
			Node* cur = _root;//������ʱ�ڵ�
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
					return true;//�����ҵ���
				}
			}
			return false;//û�ҵ��Ż��ѭ��
		}

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)//���ҵ�������ɾ��
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
				else//������˵���ҵ������������ڵ�cur
				{
					if (cur->_left == nullptr)//��Ϊ�գ��Ͱ��Ҹ����׽ڵ㣨Ϊ��Ҳ�޷���
					{
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_right)//cur��parent�ң��Ǿͽӵ��Ҳ�
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
							if (cur == parent->_right)//cur��parent�ң��Ǿͽӵ��Ҳ�
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
					else//���Ҷ����ǿգ�ʹ���滻������������������С����
					{
						Node* rightMinParent = cur;//��������С�ĸ��׽ڵ�
						Node* rightMin = cur->_right;//��������С�Ľڵ�

						while (rightMin->_left)//��ʼ��
						{
							rightMinParent = rightMin;
							rightMin = rightMin->_left;
						}

						cur->_key = rightMin->_key;//��ֵһ��������ɾrightMin������

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

		bool InsertR(const K& key)//�ѵ����ڣ�����븸�׽ڵ��������
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
				return false;//˵��û�ҵ����ͷ��ؿ�
			}

			if (root->_key < key)
			{
				return _EraseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EraseR(root->_left, key);
			}
			else//�ҵ���
			{
				Node* del = root;//����һ�£�����Ҫdelete��

				//����������ÿ�ʼ���ӵ����ã�����ֱ�ӽ�������
				if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else//����ʹ���滻����������Σ�ֱ�ӽ�������ȥ��������ݹ�
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

		bool InsertR(Node*& root,const K& key)//Ϊ�˽��������⣬������&���������
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
			if (root == nullptr)//�����û�ҵ�
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

		Node* _root = nullptr;//ͷ���
	};
}