#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_TREE_SIZE 100 // �������ڵ���

typedef struct {
    int data; // �ڵ�����
    PTNode* parent; // ָ�򸸽ڵ��ָ�������
} PTNode;

typedef struct {
    PTNode* nodes; // �洢���нڵ�����飨Ҫ��̬�ģ�
    int n; // ���е�ǰ�ڵ���
} PTree;


typedef struct CSNode {
    int data; // �ڵ�����
    struct CSNode* firstChild; // ָ���һ���ӽڵ��ָ��
    struct CSNode* nextSibling; // ָ�����ֵܽڵ��ָ��
} CSNode;


