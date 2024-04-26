#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

struct Tree 
{
	char data;//这里我指明放char了
	struct Tree* Lchild;
	struct Tree* Rchild;
	Tree(const char& d) 
	{
		data = d;
		Lchild = Rchild = NULL;
	}
};

// 创建二叉树
Tree* CreateTree(int& i, const char* arr) 
{
	if (arr[i] == '#' || arr[i] == '\0') 
	{
		i++;
		return NULL;
	}

	Tree* T = new Tree(arr[i++]);
	T->Lchild = CreateTree(i, arr);
	T->Rchild = CreateTree(i, arr);
	return T;
}

// 计算二叉树深度
int Depth(Tree* T) 
{
	if (T == NULL)
		return 0;

	int leftDepth = Depth(T->Lchild);
	int rightDepth = Depth(T->Rchild);
	return max(leftDepth, rightDepth) + 1;
}

// 计算叶子节点个数
int CountLeaves(Tree* root) 
{
	if (root == NULL)
		return 0;
	if (root->Lchild == NULL && root->Rchild == NULL)
		return 1;
	return CountLeaves(root->Lchild) + CountLeaves(root->Rchild);
}

int main() 
{
	int i = 0;
	char arr[100];
	cout << "输入二叉树: ";
	cin.getline(arr, 100);
	Tree* root = CreateTree(i, arr);

	cout << "高度: " << Depth(root) << endl;
	cout << "叶子节点数量: " << CountLeaves(root) << endl;

	return 0;
}