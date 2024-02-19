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
                    cur = cur->_left;
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
                    else//都不空：使用换位删
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
