//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int a = 7;//��������ʱ�����ڴ��￪�ٵ�һƪ�ռ�
//	int* pa = &a;//�������ǶԱ���a��ȡ�����ĵ�ַ������ʹ��&������
//	//a����ռ��4���ֽڵĿռ䣬�����ǽ�a��4���ֽڵĵ�һ���ֽڵĵ�ַ�����p����
//	//�У�p����һ��ָ֮�����
//	return 0;
//}
//
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}
//
//int main()
//{
//	int* pa;
//	*pa = 10;
//	return 0;
//}
//
//int* createInt() {
//	int num = 5;
//	int* ptr = &num;
//	return ptr;
//}
//
//int main() {
//	int* ptr = createInt();
//	printf("%d\n", *ptr);  // ���5���������ǲ���ȫ�Ĳ���
//
//	// ����֮��ptr��Ϊ��Ұָ�룬��Ϊ��ָ����ڴ�ռ��Ѿ����ͷ�
//
//	printf("%d\n", *ptr);  // δ�������Ϊ�������������ֵ���³������
//
//	return 0;
//}