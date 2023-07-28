#pragma once//该头文件进行函数的、常数的声明
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define mineNum 10

void intiBoard(char mine[ROWS][COLS], int rows, int cols,char set);

void displayBoard(char board[ROWS][COLS], int rows, int cols);

void setMine(char board[ROWS][COLS], int row, int col);

void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);