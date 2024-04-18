#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_NODES 100
//
//// 定义二叉树节点结构体
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
//    // 初始化树
//    memset(tree, 0, sizeof(tree));
//
//    // 添加节点信息
//    strcpy(tree[1].name, "A");
//    strcpy(tree[2].name, "B");
//    strcpy(tree[3].name, "C");
//    tree[1].leftChild = 2;
//    tree[1].rightChild = 3;
//    tree[2].parent = 1;
//    tree[3].parent = 1;
//
//    // 输入节点名称
//    char nodeName[20];
//    printf("请输入节点名称：");
//    scanf("%s", nodeName);
//
//    // 查找节点信息
//    for (int i = 1; i < MAX_NODES; i++) 
//    {
//        if (strcmp(tree[i].name, nodeName) == 0) {
//            printf("节点 %s 的双亲节点是 %s，孩子节点是 %s 和 %s\n", nodeName, tree[tree[i].parent].name, tree[tree[i].leftChild].name, tree[tree[i].rightChild].name);
//            break;
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>

using namespace std;

// 定义二叉树节点结构体
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

// 创建节点函数
TreeNode* createNode(string ch)
{
    TreeNode* newNode = new TreeNode(ch);
    return newNode;
}

int main() 
{
    // 创建二叉树节点
    TreeNode* root = createNode("A");
    TreeNode* nodeB = createNode("B");
    TreeNode* nodeC = createNode("C");

    // 建立节点之间的关系
    root->leftChild = nodeB;
    root->rightChild = nodeC;
    nodeB->parent = root;
    nodeC->parent = root;

    // 输入节点名称
    string nodeName;
    cout << "请输入节点名称：";
    cin >> nodeName;

    // 查找节点信息
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
        cout << "节点 " << nodeName << " 的双亲节点是 ";
        if (targetNode->parent != nullptr) {
            cout << targetNode->parent->data;
        }
        else {
            cout << "NULL";
        }
        cout << "，孩子节点是 ";
        if (targetNode->leftChild != nullptr) {
            cout << targetNode->leftChild->data;
        }
        else {
            cout << "NULL";
        }
        cout << " 和 ";
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
        cout << "未找到节点 " << nodeName << endl;
    }

    // 释放节点内存
    delete root;
    delete nodeB;
    delete nodeC;

    return 0;
}
