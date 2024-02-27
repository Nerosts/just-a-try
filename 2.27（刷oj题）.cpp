#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& pre_index, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_index++]);//就先跳到下一个
        int in_index = inbegin;
        while (root->val != inorder[in_index])
        {
            in_index++;
        }
        // while(in_index<=inend)
        // {
        //     if(root->val==inorder[in_index])
        //     {
        //         break;
        //     }
        //     in_index++;
        // }
        root->left = _buildTree(preorder, inorder, pre_index, inbegin, in_index - 1);
        root->right = _buildTree(preorder, inorder, pre_index, in_index + 1, inend);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int i = 0;//引用必须变量，不能直接引用0
        return _buildTree(preorder, inorder, i, 0, n - 1);
    }
};