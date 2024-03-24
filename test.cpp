#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
using namespace std;

const int SIZE = 100;
template <typename T>
class Stack
{
private:
	T stack[SIZE];//大小固定
	int top;
public:
	Stack() { top = 0; };//指向栈顶的下一个
	void push(T n);
	T pop();
	T Top();
	bool empty();
};

template <class T> void Stack<T>::push(T n)
{
	if (top == SIZE)
	{
		cout << "栈已满!!" << endl;
		return;
	}
	stack[top] = n;
	top++;
}
template <class T> T Stack<T>::pop()
{
	if (top == 0)
	{
		cout << "栈空不能出栈!" << endl;
		return 0;
	}
	top--;
	return stack[top];
}
template <class T> 
T Stack<T>::Top()
{
	if (top == 0)
	{
		cout << "栈为空，无法获取栈顶元素！" << endl;
		return 0;
	}
	return stack[top - 1];
}

template <class T> 
bool Stack<T>::empty()
{
	return top == 0;
}

void test1_1()
{
	stack<int> st;
	int n, b;
	cin >> n >> b;
	while (n != 0)
	{
		st.push(n % b);
		n /= b;
	}
	while (!st.empty())
	{
		int a = st.top();
		if (a < 10)
		{
			cout << a;
		}
		else
		{
			char c = 'A' + (a - 10);
			cout << c;
		}
		st.pop();
	}
}
void test1_2()
{
	Stack<int> st;
	int n, b;
	cin >> n >> b;
	while (n != 0)
	{
		st.push(n % b);
		n /= b;
	}
	while (!st.empty())
	{
		int a = st.Top();
		if (a < 10)
		{
			cout << a;
		}
		else
		{
			char c = 'A' + (a - 10);
			cout << c;
		}
		st.pop();
	}
}




void test2_1()
{
	stack<char> st;
	string str;
	int i = 0;
	cin >> str;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);  // 进栈
		}
		else if (str[i] == ')')
		{
			if (st.empty())
			{  // 栈空了
				cout << "Wrong" << endl;
			}
			else
			{
				st.pop();  // 出栈找一个左括号
				if (!st.empty())
				{  // 栈非空
					cout << "Wrong" << endl;
				}
				else
				{
					cout << "OK" << endl;
				}
			}

		}
	}
}

void test2_2()
{
	Stack<char> st;
	string str;
	int i = 0;
	cin >> str;
	for (i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);  // 进栈
		}
		else if (str[i] == ')')
		{
			if (st.empty())
			{  // 栈空了
				cout << "Wrong" << endl;
			}
			else
			{
				st.pop();  // 出栈找一个左括号
				if (!st.empty())
				{  // 栈非空
					cout << "Wrong" << endl;
				}
				else
				{
					cout << "OK" << endl;
				}
			}

		}
	}
}

int main()
{
	//test2_1();
	test2_2();
	return 0;
}


