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
//	FILE* f = fopen("./test.txt", "w");//��
//	if (f == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�ڴ򿪹ر�֮�䣬�����ܽ����ļ�����
//	const char* str = "this's test.txt";
//	fputs(str, f);
//
//	fclose(f);//�ر�
//	return 0;
//}

struct file
{
    int type; 
    int mode; 
    int pos;
 //��������
    size_t(*read)(XXX);//�������ĺ���ָ��
    size_t(*write)(XXX);//д����
    struct file* next,
};

read()
{
    return file->read(XX);
}

int main()
{
    close(1);//�ѱ�׼�������������
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    printf("%d\n", fd);
    return 0;
}