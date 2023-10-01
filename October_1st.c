#define _CRT_SECURE_NO_WARNINGS 1
/* strncat example */
#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include<assert.h>
//int main()
//{
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "To be ");
//	strcpy(str2, "or not to be");
//	strncat(str1, str2, 6);
//	puts(str1);
//	return 0;
//}

//int main()
//{
//	int a = islower('3');
//	printf("%d", a);
//	return 0;
//}

//int main()
//{
//	char arr[] = "Hellow,World";
//	for (int i = 0; i < strlen(arr); i++)
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		else
//		{
//			arr[i] = tolower(arr[i]);
//		}
//	}
//	printf("%s", arr);
//	return 0;
//}
void* my_memcpy(void* destination,const void* source, int size)
{
	assert(destination && source);
	while (size--)
	{
		*(char*)destination = *(char*)source;
		destination = (char*)destination + 1;
		source = (char*)source + 1;
	}
}


int main()
{
	int arr[] = { 1,2,4,5,6 };
	int arr2[10];
	my_memcpy(arr2, arr, sizeof(arr));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",arr2[i]);
	}
	return 0;
}