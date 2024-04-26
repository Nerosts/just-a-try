#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

struct Tree 
{
	char data;//������ָ����char��
	struct Tree* Lchild;
	struct Tree* Rchild;
	Tree(const char& d) 
	{
		data = d;
		Lchild = Rchild = NULL;
	}
};

// ����������
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

// ������������
int Depth(Tree* T) 
{
	if (T == NULL)
		return 0;

	int leftDepth = Depth(T->Lchild);
	int rightDepth = Depth(T->Rchild);
	return max(leftDepth, rightDepth) + 1;
}

// ����Ҷ�ӽڵ����
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
	cout << "���������: ";
	cin.getline(arr, 100);
	Tree* root = CreateTree(i, arr);

	cout << "�߶�: " << Depth(root) << endl;
	cout << "Ҷ�ӽڵ�����: " << CountLeaves(root) << endl;

	return 0;
}