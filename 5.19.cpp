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
	// ���캯��˽��
	Singleton(int a = 0, int b = 0) :_a(a), _b(b) {};//�����Ͷ����˴��������·


	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;//��ֹ����

	int _a;
	int _b;

	static Singleton* _single;//������Ǹ�Ψһ�Ķ���
};

Singleton* Singleton::_single = nullptr;  // �ڳ������֮ǰ����ɵ�������ĳ�ʼ��


int main()
{
	int a = 10;
	int b = move(a);
	int&& righta = move(a);
	return 0;
}