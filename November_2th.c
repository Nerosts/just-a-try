#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void swap(char* a, char* b, int size)
{
	for (int i = 1; i <= size; i++)
	{
		char t = *a;
		*a = *b;
		*b = t;
		a++;
		b++;
	}
}

void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int cmp_int(void* a, void* b)
{
	return *(int*)a - *(int*)b;
}

int cmp_byage(void* a, void* b)
{
	return ((struct Stu*)a)->age - ((struct Stu*)b)->age;
}



void bubble_qsort(void* p, size_t len, size_t size, int(*cmp)(void* a, void* b))
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if ((cmp((char*)p + j * size, (char*)p + (j + 1) * size) > 0))
			{
				swap((char*)p + j * size, (char*)p + (j + 1) * size, size);
			}
		}
	}
}

void test1()
{
	int arr[5] = { 1,2,81,11,88 };
	print(arr, 5);
	bubble_qsort(arr,5,sizeof(int),cmp_int);
	print(arr, 5);
}

void test2()
{
	struct Stu arr[3] = { {"zy",18},{"bp",17},{"xg",19} };
	bubble_qsort(arr, 3, sizeof(arr[0]), cmp_byage);
}

struct Stu
{
	char name[5];
	int age;
};
int main()
{
	//test1();

	test2();
	return 0;
}