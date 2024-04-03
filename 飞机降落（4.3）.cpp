#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


int firstDigit(int n)
{
	while (n>10)
	{
		n /= 10;
	}
	return n;
}

int N;
vector<int> num;
int minDeletes = INT_MAX;

void dfs(int idx, int deletes) 
{
    // 当前位置达到末尾时更新最少删除数目
    if (idx == N) 
    {
        minDeletes = min(minDeletes, deletes);
        return;
    }

    // 尝试删除当前数，继续向后搜索
    dfs(idx + 1, deletes + 1);

    // 如果当前数与下一个数满足接龙条件，则保留当前数并继续向后搜索
    if (idx < N - 1 && num[idx] % 10 == firstDigit(num[idx + 1])) 
    {
        dfs(idx + 1, deletes);
    }
}

int main() 
{
    cin >> N;

    num.resize(N);
    for (int i = 0; i < N; ++i) 
    {
        cin >> num[i];
    }

    // 从第一个数开始搜索
    dfs(0, 0);

    cout << minDeletes << endl;

    return 0;
}


//int main()
//{
//	cin >> N;
//	int count = 0;
//	vector<int> num(N);
//	vector<int> num2(2 * N);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> num[i];
//		if (i == 0)
//		{
//			num2.push_back(num[i] % 10);
//		}
//		else if (i == N - 1)
//		{
//			num2.push_back(firstDigit(num[i]));
//		}
//		else
//		{
//			num2.push_back(firstDigit(num[i]));
//			num2.push_back(num[i] % 10);
//		}
//	}
//	//两个数组弄好了
//	int target = -1;
//	while (target != -1)
//	{
//		target = -1;
//		for (int i = 0; i < num2.size() - 1; i += 2)
//		{
//			if (num2[i] != num2[i + 1])
//			{
//				target = i+1;
//				count++;
//				break;
//			}
//		}
//		if (target != -1)
//		{
//			num2.erase(num2.begin() + target);
//			num2.erase(num2.begin() + target + 1);
//		}
//	}
//	printf("%d", count);
//	return 0;
//}


//typedef struct plane
//{
//	int t, d, l;
//}plane;
//
//bool dfs(int num, int time, vector<bool>& flag,vector<plane>& p)
//{
//	if (num >= N)
//	{
//		return true;//到了一种结果
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (flag[i] == false)//落过的标记为true
//		{
//			flag[i] = true;
//			if (p[i].t + p[i].d < time)//到达时间+能悬停时间《 上一级飞机降落时间
//			{
//				flag[i] = false;
//				return false;
//			}
//			int t= max(time, p[i].t) + p[i].l;//降落成功的时间
//			if (dfs(num + 1, t, flag, p))
//			{
//				return true;
//			}
//			//到这里就说明后面的方案不行，这架飞机也要从新安排，变为false
//			flag[i] = false;
//		}
//	}
//	return false;
//}
//
//void solve()
//{
//	cin >> N;
//	//plane[N];
//	vector<plane> p(N);
//	for (int i = 0; i < N; i++) 
//	{
//		cin >> p[i].t >> p[i].d >> p[i].l;
//	}
//	vector<bool> flag(N,false);
//	if (dfs(0, 0, flag,p))
//		cout << "YES" << endl;
//	else
//		cout << "NO" << endl;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int t = 0;
//	cin >> t;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}

