#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main(int argc, char* argv[], char* envp[]) 
//{
//    printf("���������б�\n");
//    for (int i = 0; envp[i] != NULL; i++) 
//    {
//        printf("%s\n", envp[i]);
//    }
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

//int main() 
//{
//    char* path = getenv("USER");
//    if (path != NULL) 
//    {
//        printf("USER: %s\n", path);
//    }
//    else 
//    {
//        printf("USER environment variable not found.\n");
//    }
//    return 0;
//}

#include <stdio.h>
#include <unistd.h>
int a;
int init_a = 0;
int main(int argc, char* argv[], char* env[])
{
	printf("code:%p\n", main);//����

	printf("uninit data:%p\n", &a);//δ��ʼ������
	printf("init data:%p\n", &init_a);//��ʼ������

	char* arr = (char*)malloc(10);
	printf("heap:%p\n", arr);//��

	printf("stack:%p\n", &arr);//ջ

	for (int i = 0; argv[i]; i++)
	{
		printf("&argv[%d]:%p\n",i, argv+i);//�������ַ
	}
	for (int i = 0; argv[i]; i++)
	{
		printf("&argv[%d]:%p\n", i, argv[i]);//���������ݵ�ַ
	}

	for (int i = 0; env[i]; i++)
	{
		printf("&env[%d]:%p\n", i, env + i);//�������ַ
	}
	for (int i = 0; env[i]; i++)
	{
		printf("&env[%d]:%p\n", i, env + i);//�������ַ
	}
	return 0;
}
//extern char** environ;
//
//int main() 
//{
//    char** env = environ;
//    while (*env != NULL) 
//    {
//        printf("%s\n", *env);
//        env++;
//    }
//    return 0;
//}
