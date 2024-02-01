#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;

//int main()
//{
//	queue<int> q;//一个空队列
//	q.push(1);
//	q.push(2);
//	q.push(3);//push进去3个
//	while (!q.empty())//当q不空进循环
//	{
//		cout << q.front() << endl;//输出队头元素
//		q.pop();//出队
//	}//遍历结束
//	return 0;
//}

int main()
{
	queue<int> q;//一个空队列
	q.push(1);
	q.push(2);
	q.push(3);//push进去3个
	while (!q.empty())//当q不空进循环
	{
		cout << q.front() << endl;//输出队头元素
		q.pop();//出队
	}//遍历结束
	return 0;
}

