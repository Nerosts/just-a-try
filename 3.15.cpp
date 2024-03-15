#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

//int main()
//{
//	vector<int> v;//0表示没出列，1表示出列了
//	v.resize(105);
//	int m = 0, n = 0;
//	cin >> n >> m;
//
//	int num_per = 0;//已经出列的人数
//	int num = 0;//报数
//	while (num_per < n)//直到所有人都出列才出循环
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (v[i] == 0)
//			{
//				++num;//没出列先报数
//				if (num % m == 0)
//				{
//					v[i] = 1;
//					cout << i+1 << " ";//下标总是比人的序号少1
//					++num_per;
//				}
//			}
//		}
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

int a[150]; // 用于模拟循环链表的数组
int n, m, i, j, num; // n为总人数，m为报数的数字，i为当前报数的数字，j为当前所在人的编号，num为已出列的人数

int main()
{
    cin >> n >> m; // 输入总人数和报数的数字

    // 初始化循环链表数组
    for (i = 1; i <= n - 1; i++) {
        a[i] = i + 1;
    }
    a[n] = 1; // 最后一个人的下一个是第一个人

    i = 1; // 初始报数为1
    j = 1; // 初始所在人为第一个

    // 循环直到所有人都出列
    while (num < n)
    {
        j = a[j]; // 移动到下一个人
        i++; // 报数加1

        // 判断是否需要出列
        if (i == m)
        {
            cout << a[j] << " "; // 输出出列的人的编号
            a[j] = a[a[j]]; // 从链表中移除出列的人
            num++; // 已出列人数加1
            i = 1; // 重新开始报数
        }
     
    }

    return 0;
}
