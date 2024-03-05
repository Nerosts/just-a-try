#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int dest = -1;
        while (cur < nums.size())
        {
            if (nums[cur] == 0)
            {
                cur++;
            }
            else
            {
                dest++;
                swap(nums[dest], nums[cur]);
                cur++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        int dest = -1;
        while (cur < nums.size())
        {
            if (nums[cur] != 0)
            {
                dest++;
                swap(nums[dest], nums[cur]);

            }
            cur++;
        }
    }
};