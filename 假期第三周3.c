#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a = 0x11223344;
//	return 0;
//}

//int check_sys()
//{
//	int i = 1;
//	char* pi = *(char*)&i;
//	return (*pi);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	*pFloat = 9.0;
//	printf("更改后n的值为：%d\n", n);
//	printf("更改后*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

int main()
{
	int arr[3 + 7] = { 1,2,3 };
	int b = 0;
	char a[3];
	scanf("%d %s", &b, &a);

	return 0;
}