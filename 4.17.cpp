#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char* const env[] = {
		(char*)"first",
		(char*)"second",
		NULL };

	pid_t id = fork();
	if (id == 0)
	{
		printf("I'm a process, pid: %d\n", getpid());
		printf("execl begin...\n");

		execle("./mytest", "mytest", NULL, environ)

		printf("execl end...\n");
		exit(1);
	}

	pid_t rid = waitpid(id, NULL, 0);
	if (rid > 0)
	{
		printf("wait successfully\n");
	}
	return 0;
}

#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
	for (int i = 0; environ[i]; i++)
	{
		printf("env[%d]: %s\n", i, environ[i]);
	}

	cout << "hello C++" << endl;
	return 0;
}