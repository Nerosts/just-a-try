#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int globalVar = 1;//ȫ�ֱ������ھ�̬��
static int staticGlobalVar = 1;//ȫ�־�̬�������ھ�̬��

//int main()
//{
//	static int staticVar = 1;//�ֲ���̬�������ھ�̬����������ֻ����������ڣ�������������������������
//	int localVar = 1;//�ֲ���������ջ
//	int num1[10] = { 1, 2, 3, 4 };//�ֲ���������ջ
//
//	char char2[] = "abcd"; //�ֲ���������ջ��
//	//��ʵ[]������ţ��ǰ�λ�ڳ�������"abcd"��������ջ�ϣ���ȥָ��
//
//	const char* pChar3 = "abcd";//pChar3��ջ�ϣ�������ֱ��ָ��������"abcd"������*pChar3�ڳ�����
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);//ptr1���ָ�����������ջ������*ptr1���ڶ���
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//
//	return 0;
//}

//int main()
//{
//	 ��̬����һ��int���͵Ŀռ�
//	int* a = new int;
//
//	 ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ11
//	int* b = new int(11);
//
//	 ��̬����3��int���͵Ŀռ�
//	int* c = new int[3];
//
//	 ��̬����10��int���͵Ŀռ䣬�����в��ֳ�ʼ��
//	int* d = new int[10]{ 1,2,3 };
//
//
//	delete a;
//	delete b;
//	delete[] c;
//	delete[] d;
//	return 0;
//}

class A
{
public:
	A(int a=0)
		:_a(a)
	{}
	~A()
	{
		cout << "������~A()" << endl;
	}
private:
	int _a;
};

//int main()
//{
//	//��̬����һ��A���͵Ŀռ�
//	A* pa1 = new A(1);
//
//	//��̬����3��A���͵Ŀռ�
//	A a1;
//	A a2;
//	A a3;
//	A* pa2 = new A[3]{ a1, a2, a3 };
//	//����ֱ��д����������
//	A* pa3 = new A[3]{ A(1), A(2), A(3) };//��������
//	//���ٵ�
//	A* pa4 = new A[3]{ 1,2 ,3 };//��ʽ����ת�����е��βεĹ��캯��֧��
//
//	delete pa1;
//	delete[] pa2;
//	delete[] pa3;
//	return 0;
//}

int main()
{
	A*
	return 0;
}