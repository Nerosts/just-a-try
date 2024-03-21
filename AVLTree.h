#pragma once

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;//���׽ڵ�
	int _bf; // balance factor ƽ������
	pair<K, V> _kv;//ÿ���ڵ����һ��pair

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)//��ֱ���ڳ�ʼ���б����ʼ����
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;//����̫���ˣ���NodeҲ�������
public:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;//Ҫ��Ϊ����
		Node* subRL = subR->_left;//Ҫ��Ϊ30��������

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;//��һ�£��¸���������
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)//parent��pp���������µĸ�subRҲҪ��
			{
				ppnode->_left = subR;
			}
			else//ͬ��
			{
				ppnode->_right = subR;
			}
			subR->_parent = ppnode;
		}

		//����ƽ������
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
		int bf = subLR->_bf;//��һ�£�����Ҫ����bf

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
		if (_root == nullptr)//����ǿ���
		{
			_root = new Node(kv);
			return true;//����ɹ�
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)//���￪ʼ��λ��
		{
			if (kv.first < cur->_kv.first)//С��������
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
				return false;//��������ȵ�
			}
		}
		//��ʼ���½ڵ�������
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

		//����ƽ������
		while (parent != nullptr)//cur�����ڵ�ͣ��
		{
			if (cur == parent->_left)//�����--
			{
				parent->_bf--;
			}
			else//����++
			{
				parent->_bf++;
			}
			//��ʼ��鸸�׽ڵ�����
			if (parent->_bf == 0)
			{
				break;//ֱ��ֹͣ
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;//������
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//�ƻ��˹����ˣ���ʼ��ת
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

				break;//��������ƽ���ˣ�Ҳ�������ϣ�ֱ�ӳ�ȥ
			}
			else
			{
				// �ᵽ��˵������֮ǰAVL����������
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
			cout << root->_kv.first << "��ƽ��" << endl;
			return false;
		}
		h= leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return true;
	}

private:
	Node* _root = nullptr;//����ȱʡֵ
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
