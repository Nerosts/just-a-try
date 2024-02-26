#define _CRT_SECURE_NO_WARNINGS 1
//第一种方法；看二者是不是一个在左一个在右或者一个在另一个子数里
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
            return nullptr;//先处理空
        if (root == p || root == q)
        {
            return root;//当其中一个是祖先，就直接返回
        }

        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = IfInTree(root->left, p);
        pInRight = !pInLeft;//在右不在左

        qInLeft = IfInTree(root->left, q);
        qInRight = !qInLeft;//在右不在左

        if ((pInLeft && qInRight) || (qInLeft && pInRight))
        {
            return root;
        }
        else if (pInLeft && qInLeft)//都在左那就，递归进左子树
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else //都在右
        {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};

//第二种方法，利用栈，找出路径，在路径里对比
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
        //走到这里就说明，走错了一个，要返回上一级了，走右子树
        path.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;//先处理空
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
        //中序，在这里改指向
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
