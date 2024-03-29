#define _CRT_SECURE_NO_WARNINGS 1

#include<time.h>
#include<stdlib.h>
#include"Sort.h"

void TestShellSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestHeapSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSelectSort()
{
	int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestQuickSort()
{
	int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	//int a[] = { 9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestMergeSort()
{
	//int a[] = { 6,1,2,7,9,3,4,5,10,8 };
	int a[] = { 10,6,7,1,3,9,4,2 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 20:22
void TestOP()
{
	srand(time(0));
	const int N = 10000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);

	for (int i = N - 1; i >= 0; --i)
	{
		a1[i] = rand() + i;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin7 = clock();
	//BubbleSort(a7, N);