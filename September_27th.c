#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char arr1[] = "abcd";
//	char arr2[] = "efg";
//	printf("%d", strncmp(arr1, arr2, 2));
//
//	return 0;
//}

//Ä£Äâstrstr
//char*  my_strstr(const char* a1, const char* a2)
//{
//	char* cp;
//	char* s1;
//	char* s2;
//
//	cp = a1;
//	
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = a2;
//		while (*s1 == *s2 && s1 && s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//
//int main()
//{
//		char arr1[] = "abcdefg";
//	char arr2[] = "bc";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("ÕÒ²»µ½\n");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "zyzy.com@xg";
//	char* exed = ".@";
//	char* s = strtok(arr, exed);
//	printf("%s\n", s);
//
//	s = strtok(NULL, exed);
//	printf("%s\n", s);
//
//	s = strtok(NULL, exed);
//	printf("%s\n", s);
//	return 0;
//}

int main()
{
	char arr[] = "zyzy.com@xg";
	char* exed = ".@";
	for (char* s = strtok(arr, exed); s != NULL; s = strtok(NULL, exed))
	{
		printf("%s\n", s);
	}
	return 0;
}