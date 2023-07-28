#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void intiBoard(char mine[ROWS][COLS], int rows, int cols,char set)//多设置一个字符参数来实现对多个数组各自不同的初始化的功能
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			mine[i][j] = set;
		}
	}
}


void displayBoard(char board[ROWS][COLS], int rows, int cols)
{
	printf("-------------扫雷------------\n");
	for (int i = 0; i <= ROW; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------扫雷------------\n");
}


void setMine(char board[ROWS][COLS], int row, int col)
{
	int count = mineNum;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


int getMine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x - 1][y] + mine[x][y] + mine[x + 1][y] +
		mine[x - 1][y + 1] + mine[x][y + 1] + mine[x + 1][y + 1] - 8 * '0';
}


void openBlank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x][y] == '0')
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				show[i][j] = ' ';
				
			}
		}
		mine[x][y] = ' ';
	}
}


void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win<row*col-mineNum)
	{
		printf("请输入排查雷的坐标:\n");
		scanf("%d %d", &x, &y);
		
			if (mine[x][y] == '1')
			{
				printf("很遗憾，排到了雷，被炸了。雷的位置如下（数字1代表雷）\n");
				displayBoard(mine,ROW, COL);
				break;
			}
			else
			{
				int c = getMine(mine, x, y);
				show[x][y] = (char)c;
				//openBlank(mine,show, x, y);
				displayBoard(show, ROW, COL);
				win++;
			}
	}
	if (win == row * col - mineNum)
	{
		printf("恭喜你，赢了");
		displayBoard(mine, ROW, COL);
	}
}
	

