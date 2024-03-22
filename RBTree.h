#pragma once

enum Colour//ʹ��ö�������壬����ģ���ϣʱҲ���õ����Ƶ�
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;//��ڵ�
	RBTreeNode<K, V>* _right;//�ҽڵ�
	RBTreeNode<K, V>* _parent;//���׽ڵ�
	Colour _col;//��ɫ����ͺ���
	pair<K,V> _kv;//�ڵ����pair

	RBTreeNode(const pair<K, V>& kv)//��ֱ���ڳ�ʼ���б����ʼ����
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)//�����²���Ľڵ�һ��Ҫ�Ǻ�ɫ����ɫ�Ļ���ֱ���ƻ�����
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;//����̫���ˣ���NodeҲ�������
public:
	bool Insert(const pair<K,V> kv)
	{
		if (_root == nullptr)//���Ϊ�գ�ֱ�Ӹ����½ڵ�
		{
			_root = new Node(kv);
			_root->_col = BLACK;//ע��Ĭ���Ǻ죬����ĳɺ�
			return true;
		}

		Node* parent = nullptr;//��һ�£��¸���������
		Node* cur = _root;
		while (cur)//��ʼ�Ҳ���λ��
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
				return false;//��������ȵ�
			}
		}

		cur = new Node(kv); //����Ĭ�Ϻ�ɫ��
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;//�½ڵ����ӳɹ���

		while (parent != nullptr 
			&& parent->_col == RED)//���׽ڵ�������Ǻ�������ڵ�ֱ�����㲻�õ���
		{
			Node* grandfather = parent->_parent;
			//�����������֣�parent��grandfather�������
			if (parent == grandfather->_left)//��
			{
				Node* uncle = grandfather->_right;
				//���һ�����������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//�ȱ�ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					//����������
					cur = grandfather;
					parent = cur->_parent;
				}
				else//����������岻���ڻ��ߴ�����Ϊ��
				{
					if (cur == parent->_left)//cur��parent�󣬵���
					{
						//       g
						//    p    u
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//cur��parent�ң�˫��
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
				//�����һ����ת���ˣ�����������
				break;
			}
			else//parent��grandfather��
			{
				Node* uncle = grandfather->_left;
				// ���һ�����������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else// ����������岻���ڻ��ߴ�����Ϊ��
				{
					// ��ת+��ɫ
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
		_root->_col = BLACK;//���ֱ�Ӹĸ��ڵ㣬�����پ��忼��
		return true;
	}
	void RotateL(Node* parent)//����
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

	void RotateR(Node* parent)//����
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
		//������������һ��·���ĺ�ɫ�ڵ���������Ϊ�ο�
		int ref = 0;
		Node* cur = _root;
		while (cur)
		{
			if(cur->_col==BLACK)
				ref++;
			cur = cur->_left;//��������·��
		}
		return Check(_root, 0, ref);
	}

	bool Check(Node* cur, int blackNum, int ref)
	{
		if (cur == nullptr)//==nullptr ˵��һ��·��������
		{
			if (blackNum != ref)
			{
				cout << "��ɫ�ڵ�����������" << endl;
				return false;
			}
			return true;
		}

		//���￪ʼ���û�������ĺ죬�Ϳ�ÿ��cur�ڵ�����ĸ��׾���
		if (cur->_col == RED && cur->_parent->_col == RED)
		{
			cout << cur->_kv.first << "���������ĺ�ɫ�ڵ�" << endl;
			return false;
		}

		if (cur->_col == BLACK)
		{
			blackNum++;
		}

		return Check(cur->_left, blackNum, ref)
			&& Check(cur->_right, blackNum, ref);//�ݹ��ȥ��
	}

private:
	Node* _root = nullptr;//����ȱʡֵ
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


