#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//Lily�Ͽ�ʱʹ����ĸ����ͼƬ��С������ѧϰӢ�ﵥ��
//ÿ�ζ���Ҫ����ЩͼƬ���մ�С��ASCII��ֵ��С���������պá����Ҹ�Lily��æ��ͨ����������
//Lilyʹ�õ�ͼƬʹ���ַ�"A"��"Z"��"a"��"z"��"0"��"9"��ʾ��
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int cmp(void* a, void* b)
//{
//    return *(char*)a - *(char*)b;
//}
//int main() {
//    char arr[1000];
//    gets(arr);
//    qsort(arr, strlen(arr), sizeof(char), cmp);
//    printf("%s", arr);
//    return 0;
//}

//����һ���������� nums ������������ �����±� ��
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� - 1
//

//��һ����򵥵ķ�����
int pivotIndex(int* nums, int numsSize) {

    for (int i = 0; i < numsSize; i++)
    {
        int left = 0, right = 0;
        //�����ĺ�
        for (int j = 0; j < i; j++)
        {
            left += nums[j];
        }
        //���Ҳ�ĺ�
        for (int k = i + 1; k < numsSize; k++)
        {
            right += nums[k];
        }
        if (left == right)
        {
            return i;
        }
    }
    return -1;
}

//��΢��һ���
int pivotIndex(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++)
    {
        total += nums[i];
    }
    int left = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (2 * left + nums[i] == total)
        {
            return i;
        }
        left += nums[i];
    }
    return -1;
}
