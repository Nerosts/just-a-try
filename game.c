#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3//�����к��о�Ϊ3

void menu()//��ӡ�˵��ĺ���
{
	printf("*********************\n");
	printf("******* 1. play *****\n");
	printf("******* 0. exit *****\n");
	printf("*********************\n");
}


void initBoard(char arr[ROW][COL], int a, int b)//��ʼ�����̵ĺ���
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = ' ';
		}
	}
}


void printBoard(char arr[ROW][COL], int row,int col)//��ӡ���̵ĺ���
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		for (int k = 0; k < col; k++)
		{
			printf("---");
			if (k < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
	}
}


void Player(char arr[ROW][COL], int row, int col)
{
	while (1)
	{
           printf("��ҽ������壬������������������ \n");
	    int x, y;
	    scanf("%d %d", &x, &y);
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = 'o';
			break;
		}
		printf("��λ���ѱ�ռ�ã���������������\n");
		
	}
	else
	{
		printf("�����������������");
	}
}
}


void Computer(char arr[ROW][COL], int row, int col)
{
	printf("��������\n");
	while (1)
	{
		int x, y;
	    x = rand() % row;
	    y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = 'x';
			break;
		}
	}
}


int isFull(char arr[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}


char Iswin(char arr[ROW][COL], int row, int col)//�ж���Ӯ�ĺ���
{
	for (int i = 0; i < row; i++)//�ж���
	{
		if (arr[i][0] == arr[i][1]&&arr[i][1]==arr[i][2] && arr[i][2] != ' ')
		{
			return arr[i][0];
		}
		
	}
	for (int j = 0; j < col; j++)//�ж���
	{
		if (arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j] && arr[2][j] != ' ')
		{
			return arr[0][j];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
	{
		return arr[0][0];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
	{
		return arr[0][2];
	}
	if (isFull(arr,row,col))
	{
		return 'c';
	}
	return 'k';
}


void game()
{
	char win ;
	char board[ROW][COL]; //����ʹ��һ����ά����board����ʾ���̣�ÿ�����ӿ��Դ��һ���ַ�����ʼֵΪ�ո�
	initBoard(board, ROW, COL);//initBoard����������ʼ������
	printBoard(board, ROW, COL);//printBoard����������ӡ����
	//��ʼ����
	while (1)
	{
		Player(board, ROW, COL);//�������
		printBoard(board, ROW, COL);
		win=Iswin(board, ROW, COL);//o��ʾ���Ӯ��x�ǵ���Ӯ��c��ƽ��,k�Ǽ���
		if (win != 'k')
		{
			break;
		}
		Computer(board, ROW, COL); //��������
		printBoard(board, ROW, COL);
		if (win != 'k')
		{
			break;
		}
	}
	if (win == 'o')
	{
		printf("��һ�ʤ\n");
	}
	else if (win == 'x')
	{
		printf("���Ի�ʤ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	
}






int main()
{
	int a = 1;
	srand((unsigned int)time(NULL));
	while (a)
	{
		printf("��ѡ��\n");
		menu();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();//��ʼ��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������������������\n");
			break;
		}
	}
	return 0;
}