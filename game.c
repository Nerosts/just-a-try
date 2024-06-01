#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3//定义行和列均为3

void menu()//打印菜单的函数
{
	printf("*********************\n");
	printf("******* 1. play *****\n");
	printf("******* 0. exit *****\n");
	printf("*********************\n");
}


void initBoard(char arr[ROW][COL], int a, int b)//初始化棋盘的函数
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr[i][j] = ' ';
		}
	}
}


void printBoard(char arr[ROW][COL], int row,int col)//打印棋盘的函数
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
           printf("玩家进行下棋，请输入棋子所处坐标 \n");
	    int x, y;
	    scanf("%d %d", &x, &y);
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		if (arr[x - 1][y - 1] == ' ')
		{
			arr[x - 1][y - 1] = 'o';
			break;
		}
		printf("该位置已被占用，请输入其他坐标\n");
		
	}
	else
	{
		printf("输入错误，请重新输入");
	}
}
}


void Computer(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
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


char Iswin(char arr[ROW][COL], int row, int col)//判断输赢的函数
{
	for (int i = 0; i < row; i++)//判断行
	{
		if (arr[i][0] == arr[i][1]&&arr[i][1]==arr[i][2] && arr[i][2] != ' ')
		{
			return arr[i][0];
		}
		
	}
	for (int j = 0; j < col; j++)//判断列
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
	char board[ROW][COL]; //我们使用一个二维数组board来表示棋盘，每个格子可以存放一个字符，初始值为空格
	initBoard(board, ROW, COL);//initBoard函数用来初始化棋盘
	printBoard(board, ROW, COL);//printBoard函数用来打印棋盘
	//开始下棋
	while (1)
	{
		Player(board, ROW, COL);//玩家下棋
		printBoard(board, ROW, COL);
		win=Iswin(board, ROW, COL);//o表示玩家赢，x是电脑赢，c是平局,k是继续
		if (win != 'k')
		{
			break;
		}
		Computer(board, ROW, COL); //电脑下棋
		printBoard(board, ROW, COL);
		if (win != 'k')
		{
			break;
		}
	}
	if (win == 'o')
	{
		printf("玩家获胜\n");
	}
	else if (win == 'x')
	{
		printf("电脑获胜\n");
	}
	else
	{
		printf("平局\n");
	}
	
}






int main()
{
	int a = 1;
	srand((unsigned int)time(NULL));
	while (a)
	{
		printf("请选择：\n");
		menu();
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();//开始游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	}
	return 0;
}