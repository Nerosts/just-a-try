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
            st.pop();//���ó�����˵���������Ѿ���ͷ��
            //�ĵ����Լ���
            ret.push_back(top->val);
            //��������������
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
            TreeNode* top = st.top();//���ó�����˵���������Ѿ���ͷ��

            if (top->right == nullptr || top->right == prev)
            {
                ret.push_back(top->val);
                st.pop();//���Լ�����pop��
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