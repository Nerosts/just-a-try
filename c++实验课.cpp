#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include <cmath>
using namespace std;

//1. ��д�����������¶�ת��Ϊ�����¶ȣ���ʽΪ�������������е���
//double conversion(int F)
//{
//	return (F - 32) * 5 / 9;
//}
//int main()
//{
//	int F = 0;
//	cin >> F;
//	double C=conversion(F);
//	cout << C;
//	return 0;
//}

//2. ʹ�����غ����ķ�����������������
//�����ֱ�����������������ĵ����������С���ĵ�����
//�������ĵ�����
//double distance(int x1, int y1, int x2, int y2)
//{
//	int x = x1 - x2;
//	int y = y1 - y2;
//	return sqrt(x * x + y * y);
//}
////��С�����ĵ�����
//double distance(double x1, double y1, double x2, double y2) {
//	double dx = x2 - x1;
//	double dy = y2 - y1;
//	return sqrt(dx * dx + dy * dy);
//}
//
//int main()
//{
//	int x1 = 1, y1 = 2, x2 = 4, y2 = 6;
//	double xx1 = 1.5, yy1 = 2.5, xx2 = 4.5, yy2 = 6.5;
//	double intDist = distance(x1, y1, x2, y2);
//	cout << "����������: " << intDist << endl;
//
//	double doubleDist = distance(xx1, yy1, xx2, yy2);
//	cout << "С��������: " << intDist << endl;
//	return 0;
//}

//3. ��д�������õݹ�ķ�������x��n�����õ¶���ʽ��ֵ���ù�ʽ���£�
//inline double Legendre(double x, int n)
//{
//	if (n == 0)
//	{
//		return 1.0;
//	}
//	else if (n == 1)
//	{
//		return x;
//	}
//	else
//	{
//		return ((2 * n - 1) * x * Legendre(x, n - 1) - (n - 1) * Legendre(x, n - 2)) / n;
//	}
//
//}
//int main()
//{
//	double x = 0.0;
//	int n = 0;
//	cin >> x >> n;
//	double Px=Legendre(x, n);
//	cout <<"x��n�����õ¶���ʽ��ֵ:"<< Px;
//	return 0;
//}