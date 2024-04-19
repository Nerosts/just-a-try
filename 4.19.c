#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{
    printf("%d", stdin->_fileno);
    printf("%d", stdout->_fileno);
    printf("%d", stderr->_fileno);
    return 0;
}
//int main() 
//{
//    int fd = open("test.txt", O_WRONLY | O_CREAT, 0666);
//    if (fd == -1)
//    {
//        perror("open");
//        return 1;
//    }
//
//    const char* str = "hellow write\n";
//    write(fd, str, strlen(str));
//
//    close(fd);
//    return 0;
//}

//int main()
//{
//	FILE* f = fopen("./test.txt", "w");//打开
//	if (f == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//在打开关闭之间，我们能进行文件操作
//	const char* str = "this's test.txt";
//	fputs(str, f);
//
//	fclose(f);//关闭
//	return 0;
//}

struct file
{
    int type; 
    int mode; 
    int pos;
 //其他属性
    size_t(*read)(XXX);//读方法的函数指针
    size_t(*write)(XXX);//写方法
    struct file* next,
};

read()
{
    return file->read(XX);
}

int main()
{
    close(1);//把标准输出流给关上了
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    printf("%d\n", fd);
    return 0;
}