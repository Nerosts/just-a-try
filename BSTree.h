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
        BSTree() = default;//强行生成默认构造hanshu
        BSTree(const BSTree<K>& t)
        {
            _root=copy(t);
        }
        Node* copy(Node* t)//应该在private里
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
        void Destory(Node* root)//应该在private里
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
            if (_root == nullptr)//空的时候特殊处理
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
                    return false;//不能出现一样的
                }
            }
            cur = new Node(key);
            //开始链接上
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
                else//找到了
                {
                    if (cur->_left == nullptr)//左子树是空的
                    {
                        if (parent->_left == cur)
                        {
                            parent->_left = cur->_right;
                        }
                        else
                        {
                            parent->_right = cur->_right;
                        }
                        //移交完毕
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)//右子树是空的
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
                    else//都不空：使用换位删(可以找右子树最小或者左子树最大)
                    {
                        Node* minRightParent = cur;
                        Node* minRight = cur->_right;
                        while (minRight->_left)
                        {
                            minRightParent = minRight;
                            minRight = minRight->_left;
                        }//找到了
                        cur->_key = minRight->_key;
                        //开始链接
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
                else//找到了
                {
                    if (cur->_left == nullptr)//左子树是空的
                    {
                        if (cur == _root)
                        {
                            _root = _root->_right;
                        }
                        else//不是根节点
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
                        //移交完毕
                        delete cur;
                        return true;
                    }
                    else if (cur->_right == nullptr)//右子树是空的
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
                    else//都不空：使用换位删(可以找右子树最小或者左子树最大)
                    {
                        Node* minRightParent = cur;
                        Node* minRight = cur->_right;
                        while (minRight->_left)
                        {
                            minRightParent = minRight;
                            minRight = minRight->_left;
                        }//找到了
                        cur->_key = minRight->_key;
                        //开始链接
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
                return false;//都到了null了，说明没找到
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
                    }//找到了

                    swap(cur->_key, minRight->_key);
                    _EraseR(cur->_right, key);
                }
                delete del;
                return true;
            }
        }


        void _InOrder(Node* root)//中序遍历
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
