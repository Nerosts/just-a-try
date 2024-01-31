#pragma once
#include<assert.h>
#include"reverseIterator.h"

namespace MyList
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode<T>* _prev;
        ListNode<T>* _next;
        T _data;

        ListNode(const T& x=T())
            :_prev(nullptr)
            ,_next(nullptr)
            ,_data(x)
        {}
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T> Node;
        typedef ListIterator<T, Ref, Ptr> Self;
        
        Node* _node;

        ListIterator(Node* node)//构造函数
            :_node(node)
        {}

        //ListIterator(const Self& l)//拷贝构造函数
        //    :_node(l._node)//这里是浅拷贝(写不写都行）
        //    //新创建的迭代器和原迭代器指向相同的内存地址
        //{}

        Ref operator*()
        {
            return _node->_data;
        }
        Ptr operator->()
        {
            return &(_node->_data);
        }

        Self& operator++()//前置
        {
            _node = _node->_next;//自己要更新
            return *this;
        }
        Self operator++(int)
        {
            Self s(*this);
            _node = _node->_next;
            return s;
        }

        Self& operator--()
        {
            _node = _node->_prev;//自己要更新
            return *this;
        }
        Self operator--(int)
        {
            Self s(*this);
            _node = _node->_prev;
            return s;
        }

        bool operator!=(const Self& l)
        {
            return _node != l._node;
        }
        bool operator==(const Self& l)
        {
            return _node == l._node;
        }

    };


    //template<class T, class Ref, class Ptr>
    //struct reverse_ListIterator
    //{
    //    typedef ListIterator<T, Ref, Ptr> It;
    //    typedef reverse_ListIterator<T, Ref, Ptr> Self;
    //    
    //    It _it;

    //    reverse_ListIterator(It other)//构造函数
    //        :_it(other)
    //    {}

    //    //ListIterator(const Self& l)//拷贝构造函数
    //    //    :_node(l._node)//这里是浅拷贝(写不写都行）
    //    //    //新创建的迭代器和原迭代器指向相同的内存地址
    //    //{}

    //    Ref operator*()
    //    {
    //        return _it->operator*;
    //    }
    //    Ptr operator->()
    //    {
    //        return _it->operator->;
    //    }

    //    Self& operator++()//前置
    //    {
    //        _node = _node->_next;//自己要更新
    //        return *this;
    //    }
    //    Self operator++(int)
    //    {
    //        Self s(*this);
    //        _node = _node->_next;
    //        return s;
    //    }

    //    Self& operator--()
    //    {
    //        _node = _node->_prev;//自己要更新
    //        return *this;
    //    }
    //    Self& operator--(int)
    //    {
    //        Self s(*this);
    //        _node = _node->_prev;
    //        return s;
    //    }

    //    bool operator!=(const Self& l)
    //    {
    //        return _node != l._node;
    //    }
    //    bool operator==(const Self& l)
    //    {
    //        return _node == l._node;
    //    }

    //};


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;//默认是private 不给外面用
    public:
        typedef  ListIterator<T, T&, T*> iterator;
        typedef  ListIterator<T, const T&, const T&> const_iterator;

        typedef  reserve_iterator<iterator, T&, T*> reserve_iterator;
        typedef  reserve_iterator<const_iterator,const T&,const T*> const_reserve_iterator;


        //构造函数
        list()
        {
            _head = new Node;//去调用Node的默认构造函数了
            _head->_next = _head;
            _head->_prev = _head;//带头双向循环链表是这样的
        }

        list(int n, const T& value = T())
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            for (int i = 0; i < n; ++i)
            {
                push_back(value);
            }
        }


        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            while (first != last)
            {
                push_back(*first);
                first++;
            }
        }

        list(const list<T>& lt)
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;

            iterator it = copy.begin();
            while (it != copy.end())
            {
                push_back(*it);
                it++;
            }
        }

        list<T>&  operator=(list<T> lt)
        {
            swap(lt);
            return *this;
        }

        //析构
        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }


        // List Iterator
        iterator begin()
        {
            return iterator(_head->_next);//隐式类型转换（由单参构造函数支撑）
        }
        iterator end()
        {
            return iterator(_head);
        }
        const_iterator begin()const
        {
            return const_iterator(_head->_next);
        }
        const_iterator end()const
        {
            return const_iterator(_head);
        }

        reserve_iterator rbegin()
        {
            return reserve_iterator(end());
        }
        reserve_iterator rend()
        {
            return reserve_iterator(begin());
        }


        // List Capacity
        size_t size()const
        {
            size_t size = 0;
            iterator it = begin();
            while (it != end())
            {
                size++;
                ++it;
            }
            return size;
        }
        bool empty()const
        {
            return size() == 0;
        }


   
        // List Access
        T& front()
        {
            return _head->_next->_data;
        }
        const T& front()const
        {
            return _head->_next->_data;
        }
        T& back()
        {
            return _head->_prev->_data;
        }
        const T& back()const
        {
            return _head->_prev->_data;
        }


        // List Modify
        void push_back(const T& val) //尾插
        { 
            insert(end(), val); 
        }
        void pop_back() //尾删
        { 
            erase(--end());
        }
        void push_front(const T& val) //头插
        { 
            insert(begin(), val);
        }
        void pop_front()//头删
        { 
            erase(begin());
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* cur = pos._node;
            Node* prev = pos._node->_prev;
            Node* newnode = new Node(val);//创建新节点

            newnode->_next = cur;
            cur->_prev = newnode;
            newnode->_prev = prev;
            prev->_next = newnode;

            return newnode;//隐式类型转换
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            //assert(pos != _head);

            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;

            delete cur;
            return next;
        }

        void clear()
        {
            //删除除头结点(_head)以外的节点
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }

        void swap(list<T>& l)
        {
            std::swap(_head, l._head);
        }

    private:
        Node* _head;
    };

    void print(const list<int>& lt)
    {
        for (auto e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test2()
    {
        list<int> lt(10, 1);
        list<int>::reserve_iterator it = lt.rbegin();
        while (it != lt.rend())
        {
            cout << *it << " ";
        }
    }

    

};