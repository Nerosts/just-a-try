#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("*************************\n");
	printf("****** 1.add 2.min  *****\n");
	printf("****** 3.mul 4.div  *****\n");
	printf("****** 0.exit ***********\n");
	printf("*************************\n");
}
int add(int a, int b)
{
	return a + b;
}

int min(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}

//int main()
//{
//	int input = 1;
//	int a = 0;
//	int b = 0;
//	int result = 0;
//	while (input)
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("please input two numbers");
//			scanf("%d %d", &a, &b);
//			result = add(a, b);
//			break;
//		case 2:
//			printf("please input two numbers");
//			scanf("%d %d", &a, &b);
//			result = min(a, b);
//			break;
//		case 3:
//			printf("please input two numbers");
//			scanf("%d %d", &a, &b);
//			result = mul(a, b);
//			break;
//		case 4:
//			printf("please input two numbers");
//			scanf("%d %d", &a, &b);
//			result = div(a, b);
//			break;
//		case 0:
//			printf("退出计算器"); 
//			break;
//		}
//		printf("%d\n", result);
//	}
//	return 0;
//}

//int main()
//{
//	int input = 1;
//	int a = 0;
//	int b = 0;
//	int result = 0;
//	while (input)
//	{
//		menu();
//		scanf("%d", &input);
//		
//		int(*pf[5])(int, int) = { NULL,&add,&min,&mul,&div };  
//		if (input == 0)
//		{
//			printf("退出计算器");
//		}
//		else if (input >= 1 && input <= 4)
//		{
//			printf("please input two numbers");
//			scanf("%d %d", &a, &b);
//			result=pf[input](a, b);
//			printf("%d", result);
//		}
//		else
//		{
//			printf("选错了");
//		}
//
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int* arr[] = { &a,&b,&c };//一个指针数组
//	int* (*p)[3] = &arr;
//
//	return 0;
//}
//void calculator(int(*p)(int, int))
//{
//	int a = 0;
//	int b = 0;
//	int result = 0;
//	printf("please input two numbers");
//	scanf("%d %d", &a, &b);
//	result = p(a, b);
//	printf("%d\n", result);
//}
//int main()
//{
//	int input = 1;
//	
//	while (input)
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calculator(add);
//			break;
//		case 2:
//			calculator(min);
//			break;
//		case 3:
//			calculator(mul);
//			break;
//		case 4:
//			calculator(div);
//			break;
//		case 0:
//			printf("退出计算器"); 
//			break;
//		}
//		
//	}
//	return 0;
//struct Student
//	{
//		char name[4];
//		int age;
//	};
////}
//int cmp(void* a, void* b)
//{
//	return ((struct Student*)a)->age  -  ((struct Student*)b)->age;
//}
//
//int main()
//{
//	
//	struct Student arr[3] = { {"zc",18},{"xg",19},{"bp",17} };
//	qsort(arr, 3, sizeof(arr[0]), cmp);
//	return 0;
//}

//int main()
//{
//	int matrix [4] [3] = { {1,2,3},{2,3,4},{3,4,5},{4,5,6} };
//	int input = 0;
//	int flag = 1;
//	scanf("%d", &input);
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (matrix[i][j] == input)
//			{
//				printf("找到了");
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//	if (flag)
//	{
//		printf("没找到");
//	}
//	return 0;
//}

int findnum(int a[][3], int x, int y, int f) //第一个参数的类型需要调整
{
	int i = 0, j = y - 1; //从右上角开始遍历
	while (j >= 0 && i < x)
	{
		if (a[i][j] < f) //比我大就向下
		{
			i++;
		}
		else if (a[i][j] > f) //比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 3, 5},
				  {3, 5, 7},
				  {5, 7, 9} }; //一个示例

	if (findnum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}