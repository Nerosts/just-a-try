#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
struct s
{
	int a;
	char b;
};
//int main()
//{
//	struct s s = { 1,'c' };
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	/*fputs("zynb", stdout);*/
//	fprintf(pf, "%d %c", s.a, s.b);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct s s = { 1,'c' };
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	/*fputs("zynb", stdout);*/
//	/*fprintf(pf, "%d %c", s.a, s.b);*/
//	fscanf(pf, "%d %c", &(s.a), &(s.b));
//	printf("%d %c", s.a, s.b);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3 };
//	FILE* pf = fopen("data.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//fwrite(arr, 4, 3, pf);
//	fread(arr, 4, 3, pf);
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	struct s s = { 1,'a' };
//	char arr[100];
//	sprintf(arr, "%d %c", s.a, s.b);
//	printf("%s", arr);
//	sscanf()
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//	int ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	fseek(pf, 0, SEEK_SET);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	return 0;
//}
#include<ctype.h>

int my_atoi(const char* pa)
{
	assert(pa); //avoid NULL
	int flag = 0;
	int ret = 0;
	int n = 0;

	if (*pa == '\0') //the length of pa is 0
	{
		return 0;
	}

	while (*pa == ' ')  //there is a bunch of spaces ahead
	{
		pa++;
	}

	if (*pa == '+') //before we reach the numbers,we first encounter + or -
	{
		flag = 1;
		pa++;
	}
	if (*pa == '-')
	{
		flag = -1;
		pa++;
	}

	while (*pa != '\0')
	{
		if (isdigit(*pa))
		{
			n = n * 10 + flag * (*pa - '0');
		}
		else
		{
			break;
		}
		pa++;
	}
	return n;
}

int main()
{
	char arr[] = " -18a4";
	printf("%d", my_atoi(arr));
	return 0;
}