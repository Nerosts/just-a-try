#define _CRT_SECURE_NO_WARNINGS 1

class Solution {

public:

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> vv;

        vv.resize(numRows);//�ȸ���numRows��Ԫ�أ���vv���ܴ�vector<int>

        for (int i = 0; i < numRows; i++)//��һ�н��д���

        {

            vv[i].resize(i + 1, 0);//ÿһ�����ٿ��ö�Ӧ�Ĵ�С

            vv[i].front() = vv[i].back() = 1;//�������Ҷ���1

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