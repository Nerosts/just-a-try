#pragma once
namespace open_adress
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashData//每个点存的东西，
	{
		pair<K, V> _kv;
		State _state = EMPTY;

		//HashDate()
		//{

		//}
	};
	template<class K>
	struct HashFun
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;//本身就能转成整形的
		}
	};
	//struct HashFunString
	//{
	//	size_t operator()(const string& s)
	//	{
	//		//采用阿斯扣吗加一起
	//		int ret = 0;
	//		for (auto e : s)
	//		{
	//			ret += e;//现在光加不够，abc  cba也冲突
	//			ret *= 2;
	//		}
	//		return ret;
	//	}
	//};

	template<>//特化就不用 HashTable<sting,string,HashFunString
	struct HashFun<string>
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (auto e : s)
			{
				hash += e;
				hash *= 131;
			}

			return hash;
		}
	};

	template<class K, class V, class Hash = HashFun<K>>
	class HashTable
	{
	public:
		HashTable(size_t size = 10)
		{
			_tables.resize(size);
		}

		HashData<K, V>* Find(const K& key)
		{
			Hash h;
			size_t hashi = h(key) % _tables.size();
			while (_tables[hashi]._state != EMPTY)
			{
				if (_tables[hashi]._state == EXIST && _tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				++hashi;
				hashi = h(hashi) % _tables.size();
			}
			return nullptr;
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (n * 10 / _tables.size() >= 7)//这里要扩容
			{
				HashTable<K, V, Hash> newHT(2 * _tables.size());
				for (auto& e : _tables)
				{
					if (e._state == EXIST)
						newHT.Insert(e._kv);
				}
				_tables.swap(newHT._tables);//新的插入好后，交换一下
			}
			Hash h;
			size_t hashi = h(kv.first) % _tables.size();
			while (_tables[hashi]._state == EXIST)
			{
				++hashi;
				hashi = h(hashi) % _tables.size();
			}
			_tables[hashi]._kv = kv;
			_tables[hashi]._state = EXIST;
			++_n;

			return true;
		}

		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret != nullptr)
			{
				n--;
				ret->_state = DELETE;
				return true;
			}
			return false;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n;//已有数据个数
	};
}

namespace bucket
{
	template<class K, class V>
	struct HashNode//节点是链表，里面存pair
	{
		pair<K, V> _kv;
		HashNode* _next;

		HashNode(const T& data)
			:_next(nullptr)
			, _data(data)
		{}
	};

	template<class K, class V>
	class HashTable
	{
	public:
		typedef HashNode<K, V> Node;

		HashTable(size_t size = 10)
		{
			_tables.resize(size,nullptr);
			_n = 0;
		}
		~HashTable()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(cosnt pari<K, V>& kv)
		{
			if (_n == _tables.size())
			{
				vector<Node*> newV(_tables.size() * 2, nullptr);
				for (int i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						
						//开始转移
						size_t hashi = cur->_kv.first % _tables.size() * 2;
						cur->_next = newV[hashi];
						newV[hashi] = cur;

						cur = next;
					}
				}
				_tables.swap(newV);
			}

			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);

			//直接头插
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;

			++_n;
			return true;
		}

		Node* Find(const K& key)
		{
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			size_t hashi = key % _tables.size();
			Node* cur = _tables[hashi];
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (parent == nullptr)//cur是第一个
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						parent->_next = cur->_next;
					}
					delete cur;
					--_n;
				}
				parent = cur;
				cur = cur->_next;
			}
		}

	private:
		vector<HashNode<K, V>*> _tables;//指针数组
		size_t _n;
	};
}
