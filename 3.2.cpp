#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());//排序加去重了

        vector<int> ret;
        for (auto e : s1)
        {
            if (s2.count(e))
            {
                ret.push_back(e);
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());//排序加去重了

        vector<int> ret;
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 == *it2)
            {
                ret.push_back(*it1);
                it1++;
                it2++;
            }
            else if (*it1 < *it2)
            {
                it1++;
            }
            else {
                it2++;
            }
        }
        return ret;
    }
};
class Solution {
public:
    struct com
    {
    public:
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
        {
            return p1.second > p2.second;//大于是降序
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordMap;
        for (auto& e : words)
        {
            wordMap[e]++;
        }

        vector<string> ret;
        vector<pair<string, int>> v(wordMap.begin(), wordMap.end());

        stable_sort(v.begin(), v.end(), com());

        auto it = v.begin();
        while (k--)
        {
            ret.push_back(it->first);
            it++;
        }
        return ret;
    }
};
