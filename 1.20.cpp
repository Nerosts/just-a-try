#define _CRT_SECURE_NO_WARNINGS 1
class Solution {

public:

    int removeDuplicates(vector<int>& nums) {

        if (nums.size() == 0)//处理0的情况

        {

            return 0;

        }

        int index = 1;

        int pre_index = 0;

        while (index < nums.size())//如果就一个元素，根本不会进来

        {

            if (nums[index] != nums[pre_index])

            {

                nums[pre_index + 1] = nums[index];//赋值给下一个后加一，就是新位置了，再用后面的来比

                pre_index++;

            }

            index++;

        }

        return pre_index + 1;//下标加1才是元素个数

    }

    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        int half = numbers.size() / 2;
        for (int i = 0; i < numbers.size(); i++)
        {
            int count = 0;
            for (int j = i + 1; j < numbers.size(); j++)
            {
                if (numbers[i] == numbers[j])
                {
                    count++;
                }
                if (count >= half)
                {
                    return numbers[i];
                }
            }
        }
        return numbers[0];
    }
};