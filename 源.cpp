#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

#include<iostream>
using namespace std;


//int& aaa(vector<int>& a,int& x)
//{
//    if(x==a.size())
//    {
//        return a[a.size()-1];
//    }
//    cin>>a[x++]>>aaa(a,x);
//    
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int N=0;
//    cin>>N;
//    vector<int> jewl(N);
//    for(int i=0;i<N;i++)
//    {
//        cin>>jewl[i];
//    }
//    int a=0;
//    aaa(jewl,a);
//    for(int i=0;i<N;i++)
//    {
//        cout<<jewl[i];
//    }
//    return 0;
//}

double LCM3(int n1, int n2, int n3)
{
    int m = max(max(n1, n2), n3);
    for (int i = m; ; m++)
    {
        if (i % n1 == 0 && i % n2 == 0 && i % n3 == 0)
        {
            return i;
        }
    }
}

double LCM2(int n1, int n2)
{
    int m = max(n1, n2);
    for (int i = m; ; m++)
    {
        if (i % n1 == 0 && i % n2 == 0)
        {
            return i;
        }
    }
}

double fun(vector<int>& jewl, int i, int j, int k)
{
    double s = 0;
    double left = jewl[i] * jewl[j] * jewl[k];
    double up = LCM3(jewl[i], jewl[j], jewl[k]);
    double down = LCM2(jewl[i], jewl[j]) * LCM2(jewl[i], jewl[k]) * LCM2(jewl[j], jewl[k]);
    s = left * (up / down);
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 0;
    cin >> N;
    vector<int> jewl(N);
    for (int i = 0; i < jewl.size(); i++)
    {
        cin >> jewl[i];
    }
    vector<int> ret(3);
    double s = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                double news = fun(jewl, i, j, k);
                if (news > s)
                {
                    s = news;
                    ret[0] = i;
                    ret[1] = j;
                    ret[2] = k;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << ret[i] << " ";
    }
    return 0;
}

