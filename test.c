#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

int main()
{
	ST s;
	SInit(&s);
	SPush(&s, 1);
	SPush(&s, 1);
	SPush(&s, 1);
	while (!SEmpty(&s)) //����һ��󣬾�û��
	{
		printf("%d ", s.a[s.top]);
		SPop(&s);
	}
	printf("\n");
	return 0;
}