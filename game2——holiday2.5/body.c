#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("***********************************\n");
	printf("***********  1. play **************\n");
	printf("***********  0. exit **************\n");
	printf("***********************************\n");
}


void game()
{
	char mine[ROWS][COLS] = { 0 };//底层雷的数组
	char show[ROWS][COLS] = { 0 };//表面上展示的
	intiBoard(mine, ROWS, COLS,'0');//初始化棋盘的函数
	intiBoard(show, ROWS, COLS, '#');

	
	setMine(mine, ROW, COL);
	displayBoard(show, ROW, COL);
    
	//排除雷
	findMine(mine, show, ROW, COL);
	
}



int main()//主函数主要是进行游戏的主体流程的控制——游戏的开始与游戏退出，用一个while的死循环来满足持续进行游戏的需求，input为0时退出游戏并退出循环
{
	srand((unsigned int)time(NULL));
	int input = 1;
	while (input)
	{
		menu();
		printf("请进行选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入有误，请重新输入");
			break;
		}
	}
	return 0;
}