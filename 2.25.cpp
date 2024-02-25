#define _CRT_SECURE_NO_WARNINGS 1
{}

* };

*/

class Solution {

public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        //一层出完，再入下一层

        vector<vector<int>> vv;//空的

        queue<TreeNode*> q;

        int levelsize = 0;

        if (root != nullptr)

        {

            q.push(root);

            levelsize = 1;

        }



        while (!q.empty())

        {

            vector<int> v;

            while (levelsize--)

            {

                TreeNode* node = q.front();

                v.push_back(q.front()->val);

                q.pop();



                if (node->left)

                {

                    q.push(node->left);

                }

                if (node->right)

                {

                    q.push(node->right);

                }

            }

            levelsize = q.size();

            vv.push_back(v);

        }

        reverse(vv.begin(), vv.end());

        return vv;

    }

