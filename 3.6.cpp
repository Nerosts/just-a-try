#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1;
        while (cur < arr.size())
        {
            if (arr[cur] == 0)
            {
                dest += 2;
            }
            else
            {
                dest++;
            }
            if (dest >= arr.size() - 1)
            {
                break;
            }
            cur++;
        }
        if (dest == arr.size())
        {
            arr[dest - 1] = 0;
            dest -= 2;
            cur--;
        }
        //开始复写，从后往前
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
            }
            else
            {
                arr[dest--] = arr[cur];
            }
            cur--;
        }
    }
};