#pragma once

template<class K,class V>//�ڵ�
class AVLTreeNode
{
public:
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode<K, V>* parent;
	int _bf//balance factor
	pair<K, V> _kv;

	AVLTreeNode(pair<K,V>& kv)
		:left(nullptr)
		,right(nullptr)
		,parent(nullptr)
		,_bf(0)
		,_kv(kv)
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
				else if(prev->_bf == 1|| prev->_bf == -1)
				{
					//���ϸ�
					cur = prev;
					prev = prev->parent;
				}
				else if (prev->_bf == 2 || prev->_bf == -2)
				{
					//��ת
				}
				else
				{
					assert(false);//����˵��֮ǰ���д���
				}
			}
		}
	}

private:
	Node* _root = nullptr;
};