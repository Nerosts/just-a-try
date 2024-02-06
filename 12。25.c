#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_TREE_SIZE 100 // 树中最多节点数

typedef struct {
    int data; // 节点数据
    PTNode* parent; // 指向父节点的指针或索引
} PTNode;

typedef struct {
    PTNode* nodes; // 存储所有节点的数组（要动态的）
    int n; // 树中当前节点数
} PTree;


typedef struct CSNode {
    int data; // 节点数据
    struct CSNode* firstChild; // 指向第一个子节点的指针
    struct CSNode* nextSibling; // 指向右兄弟节点的指针
} CSNode;


