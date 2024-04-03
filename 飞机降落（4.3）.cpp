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
    // ��ǰλ�ôﵽĩβʱ��������ɾ����Ŀ
    if (idx == N) 
    {
        minDeletes = min(minDeletes, deletes);
        return;
    }

    // ����ɾ����ǰ���������������
    dfs(idx + 1, deletes + 1);

    // �����ǰ������һ�����������������������ǰ���������������
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

    // �ӵ�һ������ʼ����
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
//	//��������Ū����
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
//		return true;//����һ�ֽ��
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (flag[i] == false)//����ı��Ϊtrue
//		{
//			flag[i] = true;
//			if (p[i].t + p[i].d < time)//����ʱ��+����ͣʱ�䡶 ��һ���ɻ�����ʱ��
//			{
//				flag[i] = false;
//				return false;
//			}
//			int t= max(time, p[i].t) + p[i].l;//����ɹ���ʱ��
//			if (dfs(num + 1, t, flag, p))
//			{
//				return true;
//			}
//			//�������˵������ķ������У���ܷɻ�ҲҪ���°��ţ���Ϊfalse
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

