#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>

int main()
{
	const char* s1 = "write\n";
	write(1, s1, strlen(s1));

	const char* s2 = "fprintf\n";
	fprintf(stdout, "%s", s2);

	const char* s3 = "fwrite\n";
	fwrite(s3, strlen(s3), 1, stdout);

	fork();
	return 0;
}

//int main()
//{
//	const char* s1 = "write\n";
//	write(1, s1, strlen(s1));
//
//	const char* s2 = "fprintf\n";
//	fprintf(stdout, "%s", s2);
//
//	const char* s3 = "fwrite"\n;
//	fwrite(s3, strlen(s3), 1, stdout);
//
//	return 0;
//}

//int main()
//{
//	int fd = open("log.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
//	dup2(fd, 1);
//	printf("hellow log.txt\n");
//
//	FILE* fp = fopen("log.txt", "w");
//
//
//	return 0;
//}
