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
	char mine[ROWS][COLS] = { 0 };//�ײ��׵�����
	char show[ROWS][COLS] = { 0 };//������չʾ��
	intiBoard(mine, ROWS, COLS,'0');//��ʼ�����̵ĺ���
	intiBoard(show, ROWS, COLS, '#');

	
	setMine(mine, ROW, COL);
	displayBoard(show, ROW, COL);
    
	//�ų���
	findMine(mine, show, ROW, COL);
	
}



int main()//��������Ҫ�ǽ�����Ϸ���������̵Ŀ��ơ�����Ϸ�Ŀ�ʼ����Ϸ�˳�����һ��while����ѭ�����������������Ϸ������inputΪ0ʱ�˳���Ϸ���˳�ѭ��
{
	srand((unsigned int)time(NULL));
	int input = 1;
	while (input)
	{
		menu();
		printf("�����ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("������������������");
			break;
		}
	}
	return 0;
}