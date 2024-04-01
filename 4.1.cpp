#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>

using namespace std;

void get_next(int* next, const char* T, int len) 
{
    next[0] = -1;
    int k = -1;
    for (int q = 1; q < len; q++) 
    {
        while (k > -1 && T[k + 1] != T[q]) 
        {
            k = next[k];
        }
        if (T[k + 1] == T[q]) 
        {
            k++;
        }
        next[q] = k;
    }
}

int KMP(const char* s, int len, const char* p, int plen) 
{
    int* next = new int[plen];
    get_next(next, p, plen);
    int k = -1;
    for (int i = 0; i < len; i++) 
    {
        while (k > -1 && p[k + 1] != s[i]) 
        {
            k = next[k];
        }
        if (p[k + 1] == s[i]) 
        {
            k++;
        }
        if (k == plen - 1) 
        {
            delete[] next;
            return i - plen + 1;
        }
    }
    delete[] next;
    return -1;
}

int main() 
{
    const char a[] = "abc";
    const char b[] = "b";
    int m = KMP(a, strlen(a), b, strlen(b));
    cout <<"子串的下标：" << m << std::endl;
    return 0;
}
