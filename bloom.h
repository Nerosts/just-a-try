#pragma once

#include<bitset>
#include<string>

struct HashFuncBKDR
{
	// BKDR
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};
struct HashFuncAP
{
	// AP
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if ((i & 1) == 0) // 偶数位字符
			{
				hash ^= ((hash << 7) ^ (s[i]) ^ (hash >> 3));
			}
			else              // 奇数位字符
			{
				hash ^= (~((hash << 11) ^ (s[i]) ^ (hash >> 5)));
			}
		}

		return hash;
	}
};
struct HashFuncDJB
{
	// DJB
	size_t operator()(const string& s)
	{
		size_t hash = 5381;
		for (auto ch : s)
		{
			hash = hash * 33 ^ ch;
		}

		return hash;
	}
};
//都是针对string进行返回整数的

template<size_t N, class K = string,
	class Hash1 = HashFuncBKDR,
	class Hash2 = HashFuncAP,
	class Hash3 = HashFuncDJB >
class bloom
{
public:
	void Set(const K& k)
	{
		size_t hashi1 = Hash1()(k) % M;
		size_t hashi2 = Hash2()(k) % M;
		size_t hashi3 = Hash3()(k) % M;

		_bs.set(hashi1);
		_bs.set(hashi3);
		_bs.set(hashi2);
	}
	bool Test(const K& k)
	{
		size_t hash1 = Hash1()(key) % M;
		if (_bs->test(hash1) == false)
			return false;

		size_t hash2 = Hash2()(key) % M;
		if (_bs->test(hash2) == false)
			return false;

		size_t hash3 = Hash3()(key) % M;
		if (_bs->test(hash3) == false)
			return false;

		return true;
	}

private:
	static const size_t M = 5 * N;
	bitset<M> _bs;
};