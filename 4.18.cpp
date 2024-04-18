#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_NODES 100
//
//// ����������ڵ�ṹ��
//typedef struct TreeNode 
//{
//    char name[20];
//    int parent;
//    int leftChild;
//    int rightChild;
//} TreeNode;
//
//TreeNode tree[MAX_NODES];
//
//int main() 
//{
//    // ��ʼ����
//    memset(tree, 0, sizeof(tree));
//
//    // ��ӽڵ���Ϣ
//    strcpy(tree[1].name, "A");
//    strcpy(tree[2].name, "B");
//    strcpy(tree[3].name, "C");
//    tree[1].leftChild = 2;
//    tree[1].rightChild = 3;
//    tree[2].parent = 1;
//    tree[3].parent = 1;
//
//    // ����ڵ�����
//    char nodeName[20];
//    printf("������ڵ����ƣ�");
//    scanf("%s", nodeName);
//
//    // ���ҽڵ���Ϣ
//    for (int i = 1; i < MAX_NODES; i++) 
//    {
//        if (strcmp(tree[i].name, nodeName) == 0) {
//            printf("�ڵ� %s ��˫�׽ڵ��� %s�����ӽڵ��� %s �� %s\n", nodeName, tree[tree[i].parent].name, tree[tree[i].leftChild].name, tree[tree[i].rightChild].name);
//            break;
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

// ����������ڵ�ṹ��
struct TreeNode
{
    string data;
    struct TreeNode* parent;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;

    TreeNode(string s)
        :data(s)
        , parent(nullptr)
        , leftChild(nullptr)
        , rightChild(nullptr)
    {}
};

// �����ڵ㺯��
TreeNode* createNode(string ch)
{
    TreeNode* newNode = new TreeNode(ch);
    return newNode;
}

int main() 
{
    // �����������ڵ�
    TreeNode* root = createNode("A");
    TreeNode* nodeB = createNode("B");
    TreeNode* nodeC = createNode("C");

    // �����ڵ�֮��Ĺ�ϵ
    root->leftChild = nodeB;
    root->rightChild = nodeC;
    nodeB->parent = root;
    nodeC->parent = root;

    // ����ڵ�����
    string nodeName;
    cout << "������ڵ����ƣ�";
    cin >> nodeName;

    // ���ҽڵ���Ϣ
    TreeNode* targetNode = NULL;
    if (root->data == nodeName)
    {
        targetNode = root;
    }
    else if (nodeB->data == nodeName)
    {
        targetNode = nodeB;
    }
    else if (nodeC->data == nodeName)
    {
        targetNode = nodeC;
    }

    if (targetNode != NULL)
    {
        cout << "�ڵ� " << nodeName << " ��˫�׽ڵ��� ";
        if (targetNode->parent != nullptr) {
            cout << targetNode->parent->data;
        }
        else {
            cout << "NULL";
        }
        cout << "�����ӽڵ��� ";
        if (targetNode->leftChild != nullptr) {
            cout << targetNode->leftChild->data;
        }
        else {
            cout << "NULL";
        }
        cout << " �� ";
        if (targetNode->rightChild != nullptr) {
            cout << targetNode->rightChild->data;
        }
        else {
            cout << "NULL";
        }
        cout << endl;
    }
    else
    {
        cout << "δ�ҵ��ڵ� " << nodeName << endl;
    }

    // �ͷŽڵ��ڴ�
    delete root;
    delete nodeB;
    delete nodeC;

    return 0;
}
