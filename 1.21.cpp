#define _CRT_SECURE_NO_WARNINGS 1

class Solution {

public:

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> vv;

        vv.resize(numRows);//先给好numRows个元素，即vv里能存vector<int>

        for (int i = 0; i < numRows; i++)//对一行进行处理

        {

            vv[i].resize(i + 1, 0);//每一行里再开好对应的大小

            vv[i].front() = vv[i].back() = 1;//最左最右都是1

        }



        // for(int i=2;i<numRows;i++)

        // {

        //     for(int j=1;j<i;j++)

        //     {

        //         vv[i][j]=vv[i-1][j-1]+vv[i-1][j];

        //     }

        // }



        for (int i = 0; i < numRows; i++)

        {

            for (int j = 0; j < vv[i].size(); j++)

            {

                if (vv[i][j] == 0)

                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];

            }

        }

        return vv;

    }