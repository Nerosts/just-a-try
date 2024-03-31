#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<map>
#include<string>

int& fun1()
{
	static int a = 1;
	return a;
}

int fun2()
{
	static int a = 1;
	return a;
}

int main()
{
	map<string, string> dict1 = { {"sort","ÅÅÐò"},{"string","×Ö·û´®"} };
	map<string, string>::iterator it1 = dict1.begin();
	auto it2 = dict1.end();

	//const int* a = &fun2();
	int* pa = &fun1();
	return 0;
}

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int ret=0;
//         // if(s.size()==0)
//         // {
//         //     return 0;
//         // }
//         for(int i=0;i<s.size();i++)
//         {
//             int hash[128]={0};
//             for(int j=i;j<s.size();j++)
//             {
//                 hash[s[j]]++;
//                 if(hash[s[j]]>1)
//                 {
//                     break;
//                 }
//                 ret=max(ret,j-i+1);
//             }
//         }
//         return ret;
//     }

// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int left = 0, right = 0;
        int hash[128] = { 0 };
        while (right < s.size())
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }

};