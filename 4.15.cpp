#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/wait.h> 

int main()
{
	pid_t id = fork();//�����ӽ���
	if (id == 0)
	{
		//���������ӽ���
		int count = 5;
		while (count--)
		{
			printf("child is running. pid:%d , ppid:%d\n", getpid(), getppid());
			sleep(1);
			//����ѭ��5��
		}
		printf("�ӽ��̽��˳������Ͼͱ�ɽ�ʬ����\n");
		exit(0);//�ӽ����˳���
	}
	//�����Ǹ�����
	printf("����������\n");
	sleep(10);
	printf("�����̿�ʼ������\n");
	pid_t rid = wait(NULL);//�ø����̽��������ȴ�
	if (rid > 0)
	{
		printf("wait successfully, rid:%d\n", rid);
	}
	printf("�����̻�����\n");
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
		printf("�ӽ��̽��˳������Ͼͱ�ɽ�ʬ����\n");
		exit(0);
	}

	printf("����������\n");
	sleep(10);
	printf("�����̿�ʼ������\n");
	pid_t rid = wait(NULL);
	if (rid > 0)
	{
		printf("wait successfully, rid:%d\n", rid);
	}
	printf("�����̻�����\n");
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
			//�ӽ��̽�����
			printf("wait successfully, rid: %d, status: %d, exit code: %d\n",
				rid, status, WEXITSTATUS(status));
			break;
		}
		else if (rid = 0)
		{
			//�ӽ��̻�û����
			//������дϣ�����ӽ���û�����ڼ�ϣ�������̸�ʲô
		}
		else
		{
			//�������˵��������
			perror("waitpid");
			break;
		}
	}
	return 0;
}