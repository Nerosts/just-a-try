#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    int a, b;
    vector<int> ret;
    ret.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        ret[i] = a / b;
    }
    sort(ret.begin(), ret.end());
    int gcd = ret[0];
    int lcm = ret[0];
    for (int i = 1; i < N; ++i) 
    {
        gcd = std::gcd(gcd, ret[i]);
        lcm = (lcm * ret[i]) / std::gcd(lcm, ret[i]);
    }
    printf("%d %d", ret[0], ret[N - 1]);
    
    return 0;
}