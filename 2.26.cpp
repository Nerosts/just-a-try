#define _CRT_SECURE_NO_WARNINGS 1
//��һ�ַ������������ǲ���һ������һ�����һ���һ������һ��������
class Solution {
public:

    bool IfInTree(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
            return false;

        return root == x
            || IfInTree(root->left, x)
            || IfInTree(root->right, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;//�ȴ����
        if (root == p || root == q)
        {
            return root;//������һ�������ȣ���ֱ�ӷ���
        }

        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = IfInTree(root->left, p);
        pInRight = !pInLeft;//���Ҳ�����

        qInLeft = IfInTree(root->left, q);
        qInRight = !qInLeft;//���Ҳ�����

        if ((pInLeft && qInRight) || (qInLeft && pInRight))
        {
            return root;
        }
        else if (pInLeft && qInLeft)//�������Ǿͣ��ݹ��������
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else //������
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

//�ڶ��ַ���������ջ���ҳ�·������·����Ա�
class Solution {
public:

    bool GetPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == nullptr)
            return false;

        path.push(root);
        if (x == root)
            return true;

        if (GetPath(root->left, x, path))
            return true;

        if (GetPath(root->right, x, path))
            return true;
        //�ߵ������˵�����ߴ���һ����Ҫ������һ���ˣ���������
        path.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;//�ȴ����
        stack<TreeNode*> pPath, qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};

class Solution {
public:
    void InOrderConvert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
        {
            return;
        }

        InOrderConvert(cur->left, prev);
        //�����������ָ��
        if (prev)
        {
            prev->right = cur;
        }
        cur->left = prev;

        prev = cur;

        InOrderConvert(cur->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        InOrderConvert(pRootOfTree, prev);
        TreeNode* root = pRootOfTree;
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
    }
};
