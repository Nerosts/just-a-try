#pragma once
#include"RBTree.h"
namespace MySet
{
	template<class K>
	class set
	{
		typedef typename RBTree<K,const K, SetOfKey>::iterator iterator;

		struct SetOfKey
		{
			const K& operator()(const K& k)
			{
				return k;
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

		bool Insert(const K& k)
		{
			return _t.Insert(k);
		}

	private:
		RBTree<K,const K , SetOfKey> _t;
	};
}