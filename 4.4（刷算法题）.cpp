#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

int n;
int ans = 0;

int firstDigit(int n)
{
	while (n > 10)
	{
		n /= 10;
	}
	return n;
}

void dfs(vector<int>& a,int i, int num, int last)
{
	if (i >= n)
	{
		ans = max(num, ans);
		return;
	}
	if (n - i + num <= ans)
	{
		return;
	}

	if (last == -1 || last % 10 == firstDigit(a[i]))
	{
		dfs(a, i + 1, num + 1, a[i]);
	}
	dfs(a, i + 1, num, last);
}

void solve()
{
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dfs(a,0, 0, -1);
	cout << n - ans << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}

class Solution {
public:
	int waysToStep(int n) {
		int step[n];
		if (n == 1)
		{
			return 1;
		}
		else if (n == 2)
		{
			return 2;
		}
		else if (n == 3)
		{
			return 4;
		}
		else
		{
			vector<long long> step = { 1,2,4 };//step[i]为到第i+1台阶的
			step.resize(n);
			for (int i = 3; i < n; i++)
			{
				step[i] = step[i - 1] + step[i - 2] + step[i - 3];
				step[i] = step[i] % 1000000007;
			}
			return step[n - 1] % 1000000007;
		}
	}
};