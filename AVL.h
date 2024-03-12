#pragma once

template<class K, class V>//�ڵ�
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

		Node* prev = nullptr;//��������
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
			//���Ӻ��ˣ����ڴ���_bf
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
					//ֹͣ
					break;
				}
				else if (prev->_bf == 1 || prev->_bf == -1)
				{
					//�ϸ�
					cur = prev;
					prev = prev->parent;
				}
				else if (prev->_bf == 2 || prev->_bf == -2)
				{
					//��ת
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
						RotateLR(prev);//������������
					}
					else if (prev->_bf == 2 && cur->_bf == -1)
					{
						RotateRL(prev);//��you����left��
					}
					else
					{
						assert(false);//�����Ļ����������
					}
					break;
				}
				else
				{
					assert(false);//����˵��֮ǰ���д���
				}
				
			}
		}
	}
	void RotateL(Node* parent)//����ת
	{
		Node* subR = parent->right;//��������
		Node* subRL = subR->left;//�����������
		Node* ppNode = parent->parent;//�п�����һ�����������߶�������

		parent->right = subRL;
		if (subRL)//���ǿղ���
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
		else//������
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
	void RotateR(Node* parent)//����ת
	{
		Node* subL = parent->left;//��������
		Node* subLR = subR->right;//�����������
		Node* ppNode = parent->parent;//�п�����һ�����������߶�������

		parent->right = subLR;
		if (subLR)//���ǿղ���
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
		else//������
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
		int bf = subLR->_bf;//���ȴ���һ��

		RotateL(parent->left);
		RotateR(parent);

		//��ʼ����_bf
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
		int bf = subRL->_bf;//��һ��

		RotateR(subR);
		RotateL(parent);

		//��ʼ����_bf
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