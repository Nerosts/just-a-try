#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/wait.h> 

int main()
{
	pid_t id = fork();//创建子进程
	if (id == 0)
	{
		//这里面是子进程
		int count = 5;
		while (count--)
		{
			printf("child is running. pid:%d , ppid:%d\n", getpid(), getppid());
			sleep(1);
			//这里循环5秒
		}
		printf("子进程将退出，马上就变成僵尸进程\n");
		exit(0);//子进程退出了
	}
	//这里是父进程
	printf("父进程休眠\n");
	sleep(10);
	printf("父进程开始回收了\n");
	pid_t rid = wait(NULL);//让父进程进程阻塞等待
	if (rid > 0)
	{
		printf("wait successfully, rid:%d\n", rid);
	}
	printf("父进程回收了\n");
	sleep(5);

	return 0;
}

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/wait.h> 

int main()
{
	pid_t id = fork();
	if (id == 0)
	{
		
		int count = 5;
		while (count--)
		{
			printf("child is running. pid:%d , ppid:%d\n", getpid(), getppid());
			sleep(1);
			
		}
		printf("子进程将退出，马上就变成僵尸进程\n");
		exit(0);
	}

	printf("父进程休眠\n");
	sleep(10);
	printf("父进程开始回收了\n");
	pid_t rid = wait(NULL);
	if (rid > 0)
	{
		printf("wait successfully, rid:%d\n", rid);
	}
	printf("父进程回收了\n");
	sleep(5);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t id = fork();
	if (id == 0)
	{
		int cnt = 5;
		while (cnt)
		{
			printf("Child is running, pid: %d, ppid: %d\n", getpid(), getppid());
			sleep(1);
			cnt--;
		}
		exit(1);
	}
	int status = 0;
	pid_t rid = waitpid(id, &status, 0);
	if (rid > 0)
	{
		if (WIFEXITED(status))
		{
			printf("wait successfully, rid: %d, status: %d\n", rid, status);
			printf("wait successfully, rid: %d, status: %d, exit code: %d\n", 
				rid, status,WEXITSTATUS(status));

		}
		else
		{
			printf("wait wrongly\n");
		}
		
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t id = fork();
	if (id == 0)
	{
		int cnt = 5;
		while (cnt)
		{
			printf("Child is running, pid: %d, ppid: %d\n", getpid(), getppid());
			sleep(1);
			cnt--;
		}
		exit(1);
	}

	int status = 0;
	pid_t rid = waitpid(id, &status, WNOHANG);

	while (1)
	{
		if (rid > 0)
		{
			//子进程结束了
			printf("wait successfully, rid: %d, status: %d, exit code: %d\n",
				rid, status, WEXITSTATUS(status));
			break;
		}
		else if (rid = 0)
		{
			//子进程还没结束
			//这里能写希望在子进程没结束期间希望父进程干什么
		}
		else
		{
			//到这里就说明出错了
			perror("waitpid");
			break;
		}
	}
	return 0;
}