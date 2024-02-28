#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr)
            {
                ret.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            st.pop();

            cur = top->right;
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();
            st.pop();//被拿出来能说明左子树已经到头啦
            //改到他自己了
            ret.push_back(top->val);
            //现在是右子树啦
            cur = top->right;
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur != nullptr || !st.empty())
        {
            while (cur != nullptr)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st.top();//被拿出来能说明左子树已经到头啦

            if (top->right == nullptr || top->right == prev)
            {
                ret.push_back(top->val);
                st.pop();//到自己啦才pop掉
                prev = top;
            }
            else
            {
                cur = top->right;
            }
        }
        return ret;
    }
};