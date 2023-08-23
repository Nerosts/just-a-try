#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//С��ͬѧ���������һ����վ�����û�ע���˻���ʱ����Ҫ�����˻������룬Ϊ�˼�ǿ�˻��İ�ȫ�ԣ�С��������ǿ����һ��Ҫ��
//1. ����ֻ���ɴ�д��ĸ��Сд��ĸ�����ֹ��ɣ�
//2. ���벻�������ֿ�ͷ��
//3. ���������ٳ��ִ�д��ĸ��Сд��ĸ�������������ַ������е����֣�
//4. ���볤������Ϊ8
//����С���ܵ���n�����룬��������д�����ж���Щ��������Щ�Ǻ��ʵģ���Щ�ǲ��Ϸ���
int main() {
    int n;

    scanf("%d", &n);
    while (n--)
    {
        int small = 0, big = 0, num = 0, other = 0;
        char password[101];
        scanf("%s", password);
        if (strlen(password) < 8)
        {
            printf("NO\n");

            continue;
        }
        if (password[0] >= '0' && password[0] < '9')
        {
            printf("NO\n");

            continue;
        }
        for (int i = 0; i < strlen(password); i++)
        {
            if (password[i] >= '0' && password[i] < '9')
            {
                num++;
            }
            else if (password[i] >= 'A' && password[i] < 'Z')
            {
                big++;
            }
            else if (password[i] >= 'a' && password[i] < 'z')
            {
                small++;
            }
            else
            {
                other++;
            }
        }
        if (other != 0)
        {
            printf("NO\n");

            continue;
        }
        if ((small > 0) + (big > 0) + (num > 0) < 2)
        {
            printf("NO\n");

            continue;
        }
        printf("YES\n");
    }
    return 0;
}
//����һ������Ϊ n �ķǽ��������һ���Ǹ������� k ��Ҫ��ͳ�� k �������г��ֵĴ���
//��Ϊ�򵥵�
int GetNumberOfK(int* nums, int numsLen, int k) {
    // write code here
    int count = 0;
    for (int i = 0; i < numsLen; i++)
    {
        if (k == nums[i])
        {
            count++;
        }
    }
    return count;
}

//�ö��ֲ�����do it
*@param nums int����һά����
* @param numsLen int nums���鳤��
* @param k int����
* @return int����
* /
int GetNumberOfK(int* nums, int numsLen, int k) {
    // write code here
    if (numsLen == 0)
    {
        return 0;
    }
    else if (k > nums[numsLen - 1] || k < nums[0])
    {
        return 0;
    }
    else {
        int left = 0;
        int right = numsLen - 1;
        int leftbound = 0;
        int rightbound = 0;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        leftbound = left;

        left = 0;
        right = numsLen - 1;
        while (left < right) {
            mid = (left + right) / 2 + 1;
            if (nums[mid] > k) {
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        rightbound = right;
        return rightbound - leftbound + 1;
    }
}
//����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B
int convertInteger(int A, int B) {
    int difference = A ^ B;
    int count = 0;
    for (int i = 0; i <= 31; i++)
    {
        if ((difference >> i) & 1 == 1)
        {
            count++;
        }
    }
    return count;
}