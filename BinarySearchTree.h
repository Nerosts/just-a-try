#pragma once

namespace key
{
    template<class K>
    struct BSNode
    {
        BSNode* _left;
        BSNode* _right;
        K _key;

        BSNode(const K& key)
            : _left(nullptr)
            , _right(nullptr)
            , _key(key)
        {}
    };

    template<class K>
    class BSTree
    {
        typedef BSNode<K> Node;
    public:
        bool Insert(const K& key)
        {
            if (_root == nullptr)//�յ�ʱ�����⴦��
            {
                _root = new Node(key);
                return true;
            }
            Node* parent = nullptr;
            Node* cur = _root;
            while (cur != nullptr)
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
                    return false;//���ܳ���һ����
                }
            }
            cur = new Node(key);
            //��ʼ������
            if (parent->_key > key)
            {
                parent->_left = cur;
            }
            else
            {
                parent->_right = cur;
            }
            return true;
        }
        bool Eraase(const K& key)
        {
            Node* parent = nullptr;
            Node* cur = _root;
            while (cur)
            {
                if (cur->_key > key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else if (cur->_key < key)
                {
                    parent = cur;
                    cur = cur->_left;
                }
                else//�ҵ���
                {
                    if (cur->_left == nullptr)//�������ǿյ�
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                        //�ƽ����
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)//�������ǿյ�
                    {
                        if (parent->_right == cur)
                        {
                            parent->_right = cur->_left;
                        }
                        else
                        {
                            parent->_left = cur->_left;
                        }
                        delete cur;
                        return true;
                    }
                    else//�����գ�ʹ�û�λɾ
                    {

                    }
                }
            }
            return false;
        }

        bool Find(const K& key)
        {
            Node* cur = _root;
            while (cur != nullptr)
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
                    return true;
                }
            }
            return false;
        }

        void InOrder()
        {
            _InOrder(_root);
            cout << endl;
        }

    private:
        void _InOrder(Node* root)//�������
        {
            if (root == nullptr)
            {
                return;
            }
            _InOrder(root->_left);
            cout << root->_key << " ";
            _InOrder(root->_right);
        }

    private:
        Node* _root = nullptr;
    };
}
