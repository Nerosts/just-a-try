#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//void* __CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
//{
//	void* p;
//	while ((p = malloc(size)) == 0)
//		if (_callnewh(size) == 0)
//		{
//
//			static const std::bad_alloc nomem;
//			_RAISE(nomem);
//		}
//	return (p);
//}
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK);
//	__TRY
//		pHead = pHdr(pUserData);
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); 
//	__END_TRY_FINALLY
//		return;
//}

//class Stack
//{
//public:
//	Stack(int capacity = 3)
//	{
//		cout << "调用了构造函数" << endl;
//		_a = new int[capacity];
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		delete _a;
//		_a = nullptr;
//		_top = -1;
//		_capacity = 0;
//	}
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//};

//int main()
//{
//	Stack* s1 = (Stack*)operator new(sizeof(Stack));
//	//都知道构造函数不能显示调用
//	//s1->Stack();
//
//	//但是可以使用定位new显示调用构造函数
//	new(s1)Stack(2);
//
//	//但是析构函数可以
//	s1->~Stack();
//	operator delete (s1);
//	return 0;
//}

//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(double& a, double& b)
//{
//	double temp = a;
//	a = b;
//	b = temp;
//}
//
//template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
template<class T ,class Y>
void print(T& a, Y& b)
{
	cout << a << " " << b << endl;
}

template<class T>
T add(const T& a,const  T& b)
{
	return a + b;
}

template<class T>
T* fun1(int n)
{
	return new T[n];
}

//int main()
//{
//	int* a = fun1<int>(10);
//	return 0;
//}

int add(const int a, const  int b)
{
	return a + b;
}
//
//int main()
//{
//	int a = add(1, 1);
//	double b = add(1.1, 1);
//	int a = 1.1;
//	print(a, b);
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	return 0;
//}

template<class T>
class Stack
{
public:
	Stack(int capacity = 3)
	{
		cout << "调用了构造函数" << endl;
		_a = new T[capacity];
		_top = 0;
		_capacity = capacity;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		delete _a;
		_a = nullptr;
		_top = -1;
		_capacity = 0;
	}
private:
	int* _a;
	int _top;
	int _capacity;
};

int main()
{
	// Stack是类名，Stack<int>和Stack<double>才是类型
	Stack<int> s1;
	Stack<double> s2;
	return 0;
}
