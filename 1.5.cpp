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
	// 前置++：返回+1之后的结果
	// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
	Date& operator++()
	{
		_day += 1;
		return *this;
	}

	// 后置++：
	// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递
	Date operator++(int)// 前置++和后置++都是一元运算符，加个int为了让前置++与后置++形成能正确重载
	{
		Date temp(*this);
		_day += 1;
		return temp;//temp是临时对象，因此只能以值的方式返回，不能返回引用
	}// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，然后给this + 1
private:
	int _year;
	int _month;
	int _day;
};