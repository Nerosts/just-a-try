#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ģ��ʵ��strlen
//size_t my_strlen(const char* pa)
//{
//	char* start = pa;
//	char* end = pa;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}

//ģ��ʵ��strcpy
//void my_strcpy(char* source,char* destiation)
//{
//	while (*source)
//	{
//		*destiation = *source;
//		destiation++;
//		source++;
//	}
//	*destiation = *source;
//}

//ģ��ʵ��strcmp

//int main()
//{
//	char arr1[] = "hello world";
//	char arr2[] = "*****************";
//	my_strcpy(arr1, arr2);
//		printf("%s", arr2);
//	return 0;
//}

//int compare(const void* a, const void* b) {
//    return (*(int*)a - *(int*)b);
//}
//
//int main() {
//    int arr[] = { 5, 3, 8, 2, 1, 4 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//
//    qsort(arr, size, sizeof(int), compare);
//
//    for (int i = 0; i < size; i++) {
//        printf("%d ", arr[i]);
//    }
//
//    return 0;
//}

 struct Student{
    char name[20];
    int score;
} ;

int compare(const void* a, const void* b) {
    return ((struct Student*)a)->score - ((struct Student*)b)->score;
}

int main() {
   struct Student students[] = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"David", 80},
        {"Eva", 88}
    };
    int size = sizeof(students) / sizeof(students[0]);

    qsort(students, size, sizeof(struct Student), compare);

    printf("���ճɼ�������ѧ���б�\n");
    for (int i = 0; i < size; i++) {
        printf("������%s���ɼ���%d\n", students[i].name, students[i].score);
    }

    return 0;
}