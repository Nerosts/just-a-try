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
        BSTree() = default;//ǿ������Ĭ�Ϲ���hanshu
        BSTree(const BSTree<K>& t)
        {
            _root=copy(t);
        }
        Node* copy(Node* t)//Ӧ����private��
        {
            if (t == nullptr)
            {
                return nullptr;
            }
            _root = new Node(t->_key);
            _root->_left = copy(t->_left);
            _root->_right = copy(t->_right);
        }

        BSTree<K>& operator=(const BSTree<K> t)
        {
            std::swap(t._root, _root);
            return *this;
        }

        ~BSTree()
        {
            Destory(_root);
        }
        void Destory(Node* root)//Ӧ����private��
        {
            if (root == nullptr)
            {
                return;
            }
            Destory(root->_left);
            Destory(root->_right);
            delete root;
        }

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
                    cur = cur->_right;
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
                    else//�����գ�ʹ�û�λɾ(��������������С�������������)
                    {
                        Node* minRightParent = cur;
                        Node* minRight = cur->_right;
                        while (minRight->_left)
                        {
                            minRightParent = minRight;
                            minRight = minRight->_left;
                        }//�ҵ���
                        cur->_key = minRight->_key;
                        //��ʼ����
                        if (minRight == minRightParent->_left)
                            minRightParent->_left = minRight->_right;
                        else
                            minRightParent->_left = minRight->_right;

                        delete minRight;
                        return true;
                    }
                }
            }
            return false;
        }
        bool Erase(const K& key)
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
                    cur = cur->_right;
                }
                else//�ҵ���
                {
                    if (cur->_left == nullptr)//�������ǿյ�
                    {
                        if (cur == _root)
                        {
                            _root = _root->_right;
                        }
                        else//���Ǹ��ڵ�
                        {
                            if (parent->_left == cur)
                            {
                                parent->_left = cur->_right;
                            }
                            else
                            {
                                parent->_right = cur->_right;
                            }
                        }
                        //�ƽ����
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)//�������ǿյ�
                    {
                        if (cur == _root)
                        {
                            _root = _root->_left;
                        }
                        else
                        {
                            if (parent->_right == cur)
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
                    else//�����գ�ʹ�û�λɾ(��������������С�������������)
                    {
                        Node* minRightParent = cur;
                        Node* minRight = cur->_right;
                        while (minRight->_left)
                        {
                            minRightParent = minRight;
                            minRight = minRight->_left;
                        }//�ҵ���
                        cur->_key = minRight->_key;
                        //��ʼ����
                        if (minRight == minRightParent->_left)
                            minRightParent->_left = minRight->_right;
                        else
                            minRightParent->_right = minRight->_right;

                        delete minRight;
                        return true;
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

        bool FindR(const K& key)
        {
            return _FindR(_root,key);
        }

        bool InsertR(const K& key)
        {
            return _InsertR(_root, key);
        }

        bool EraseR(const K& key)
        {
            return _EraseR(_root, key);
        }

    private:
        bool _FindR(Node* cur,const K& key)
        {
            if (cur == nullptr)
            {
                return false;//������null�ˣ�˵��û�ҵ�
            }

            if (key > cur->_key)
            {
               return _FindR(cur->_right, key);
            }
            else if (key < cur->_left)
            {
                return _FindR(cur->_left, key);
            }
            else
            {
                return true;
            }
        }

        bool _InsertR(Node*& cur, const K& key)
        {
            if (cur == nullptr)
            {
                cur = new Node(key);
                return true;
            }
            if (key < cur->_key)
            {
                return _InsertR(cur->_left, key);
            }
            else if (key > cur->_key)
            {
                return _InsertR(cur->_right, key);
            }
            else
            {
                return false;
            }
        }

        bool _EraseR(Node* cur, const K& key)
        {
            if (cur == nullptr)
            {
                return false;
            }
            if (key < cur->_key)
            {
                return _EraseR(cur->_left, key);
            }
            else if (key > cur->_key)
            {
                return _EraseR(cur->_right, key);
            }
            else
            {
                Node* del = cur;
                if (cur->_left == nullptr)
                {
                    cur = cur->_right;
                }
                else if (cur->_right == nullptr)
                {
                    cur = cur->_left;
                }
                else
                {
                    Node* minRightParent = cur;
                    Node* minRight = cur->_right;
                    while (minRight->_left)
                    {
                        minRightParent = minRight;
                        minRight = minRight->_left;
                    }//�ҵ���

                    swap(cur->_key, minRight->_key);
                    _EraseR(cur->_right, key);
                }
                delete del;
                return true;
            }
        }


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
