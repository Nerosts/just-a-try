#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
using namespace std;

//int main()
//{
//	queue<int> q;//һ���ն���
//	q.push(1);
//	q.push(2);
//	q.push(3);//push��ȥ3��
//	while (!q.empty())//��q���ս�ѭ��
//	{
//		cout << q.front() << endl;//�����ͷԪ��
//		q.pop();//����
//	}//��������
//	return 0;
//}

int main()
{
	queue<int> q;//һ���ն���
	q.push(1);
	q.push(2);
	q.push(3);//push��ȥ3��
	while (!q.empty())//��q���ս�ѭ��
	{
		cout << q.front() << endl;//�����ͷԪ��
		q.pop();//����
	}//��������
	return 0;
}

