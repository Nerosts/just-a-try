#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& pre_index, int inbegin, int inend)
    {
        if (inbegin > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[pre_index++]);//����������һ��
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
        int i = 0;//���ñ������������ֱ������0
        return _buildTree(preorder, inorder, i, 0, n - 1);
    }
};