#pragma once
#include"RBTree.h"
namespace MyMap
{
	template<class K,class V>
	class map
	{
		typedef typename RBTree<K, K, SetOfKey>::iterator iterator;

		struct MapOfKey
		{
			const T& operator()(const pair<K, V> kv)
			{
				return kv.first;
			}
		};
	public:

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		iterator Find(const K& key)
		{
			return _t.Find(key);
		}

		pair<iterator,bool> Insert(const pair<K,V>& kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K& key)
		{

		}

	private:
		RBTree<K, pair<K, V>,MapOfKey> _t;
	};
}
