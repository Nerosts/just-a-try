#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int main(int argc, char* argv[], char* envp[]) 
//{
//    printf("环境变量列表：\n");
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
	printf("code:%p\n", main);//代码

	printf("uninit data:%p\n", &a);//未初始化变量
	printf("init data:%p\n", &init_a);//初始化变量

	char* arr = (char*)malloc(10);
	printf("heap:%p\n", arr);//堆

	printf("stack:%p\n", &arr);//栈

	for (int i = 0; argv[i]; i++)
	{
		printf("&argv[%d]:%p\n",i, argv+i);//参数表地址
	}
	for (int i = 0; argv[i]; i++)
	{
		printf("&argv[%d]:%p\n", i, argv[i]);//参数表内容地址
	}

	for (int i = 0; env[i]; i++)
	{
		printf("&env[%d]:%p\n", i, env + i);//参数表地址
	}
	for (int i = 0; env[i]; i++)
	{
		printf("&env[%d]:%p\n", i, env + i);//参数表地址
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
