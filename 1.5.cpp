#define _CRT_SECURE_NO_WARNINGS 1
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// ǰ��++������+1֮��Ľ��
	// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// ����++��
	// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
	Date operator++(int)// ǰ��++�ͺ���++����һԪ��������Ӹ�intΪ����ǰ��++�����++�γ�����ȷ����
	{
		Date temp(*this);
		_day += 1;
		return temp;//temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
	}// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����һ�ݣ�Ȼ���this + 1
private:
	int _year;
	int _month;
	int _day;
};