#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

//int main()
//{
//	vector<int> v;//0��ʾû���У�1��ʾ������
//	v.resize(105);
//	int m = 0, n = 0;
//	cin >> n >> m;
//
//	int num_per = 0;//�Ѿ����е�����
//	int num = 0;//����
//	while (num_per < n)//ֱ�������˶����вų�ѭ��
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (v[i] == 0)
//			{
//				++num;//û�����ȱ���
//				if (num % m == 0)
//				{
//					v[i] = 1;
//					cout << i+1 << " ";//�±����Ǳ��˵������1
//					++num_per;
//				}
//			}
//		}
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int a[150]; // ����ģ��ѭ�����������
int n, m, i, j, num; // nΪ��������mΪ���������֣�iΪ��ǰ���������֣�jΪ��ǰ�����˵ı�ţ�numΪ�ѳ��е�����

int main()
{
    cin >> n >> m; // �����������ͱ���������

    // ��ʼ��ѭ����������
    for (i = 1; i <= n - 1; i++) {
        a[i] = i + 1;
    }
    a[n] = 1; // ���һ���˵���һ���ǵ�һ����

    i = 1; // ��ʼ����Ϊ1
    j = 1; // ��ʼ������Ϊ��һ��

    // ѭ��ֱ�������˶�����
    while (num < n)
    {
        j = a[j]; // �ƶ�����һ����
        i++; // ������1

        // �ж��Ƿ���Ҫ����
        if (i == m)
        {
            cout << a[j] << " "; // ������е��˵ı��
            a[j] = a[a[j]]; // ���������Ƴ����е���
            num++; // �ѳ���������1
            i = 1; // ���¿�ʼ����
        }
     
    }

    return 0;
}
