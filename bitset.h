#pragma once

namespace mybs
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1);
		}

		// ��xӳ���λ��ǳ�1
		void set(size_t x)
		{
			int i = x / 32;
			int j = x % 32;
			_bits[i] = _bits[i] | (1 << j);
		}

	private:
		vector<int> _bits;
	};
}
