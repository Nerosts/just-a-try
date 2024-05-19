#define _CRT_SECURE_NO_WARNINGS 1

class Singleton
{
public:
	static Singleton* GetInstance()
	{
		if (_single == nullptr)
		{
			_single = new Singleton;
		}
		return _single;
	}
private:
	// 构造函数私有
	Singleton(int a = 0, int b = 0) :_a(a), _b(b) {};//这样就堵死了创建对象的路


	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;//防止拷贝

	int _a;
	int _b;

	static Singleton* _single;//这就是那个唯一的对象
};

Singleton* Singleton::_single = nullptr;  // 在程序入口之前就完成单例对象的初始化


int main()
{
	int a = 10;
	int b = move(a);
	int&& righta = move(a);
	return 0;
}