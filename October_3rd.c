#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* sor, int size)
{
	assert(dest && sor);
	while (size--)
	{
		*(char*)dest = *(char*)sor;
		dest = (char*)dest + 1;
		sor = (char*)sor + 1;
	}
	return dest;
}

int main()
{
	int arr1[] = { 1,2,4 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, 12);
	return 0;
}

//void* my_memmove(void* dest, const void* sor, size_t size)
//{
//	if (dest < sor)//从前往后
//	{
//		for (int i = 0; i < size; i++)
//		{
//		*(char*)dest = *(char*)sor;
//		dest = (char*)dest + 1;
//		sor = (char*)sor + 1;
//		}
//		
//	}
//	else
//	{
//		for (int i = 0; i < size; i++)
//		{
//			dest = (char*)dest + size-1;
//			sor = (char*)sor + size-1;
//			*(char*)dest = *(char*)sor;
//			dest = (char*)dest - 1;
//			sor = (char*)sor - 1;
//		}
//	}
//}

//void* my_memmove(void* dest, const void* sor, size_t size)
//{
//	assert(dest && sor);
//	if (dest < sor)//从前往后
//	{
//		for (int i = 0; i < size; i++)
//		{
//			*(char*)dest = *(char*)sor;
//			dest = (char*)dest + 1;
//			sor = (char*)sor + 1;
//		}
//
//	}
//	else
//	{
//		while (size--)
//		{
//			*((char*)dest + size) = *((char*)sor + size);
//		}
//	}
//	return dest;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr, arr + 2, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}