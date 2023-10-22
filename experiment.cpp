#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include<cstdio>
using namespace std;

//void sortCountries(char* countries[], int size) {
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = 0; j < size - i - 1; j++) {
//            if (strcmp(countries[j], countries[j + 1])>0) {
//                char* temp = countries[j];
//                countries[j] = countries[j + 1];
//                countries[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    char* countries[10];
//
//    cout << "请输入10个国家名称：" << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << "国家 " << i + 1 << ": ";
//        char input[100];
//        cin >> input;
//        countries[i] = (char*)malloc(sizeof(char*));
//        strcpy(countries[i], input);
//    }
//
//    sortCountries(countries, 10);
//
//    cout << "排序后的国家名称：" << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << countries[i] << endl;
//    }
//
//    return 0;
//}

int main()
{
	char arr[10] = "abcd  3";
	cout << "请输入一个字符串";
	
	cin.getline(arr, 10);
	cout << "字符串总长度" << strlen(arr) << "\n";
	
	int num = 0;
	int sa = 0;
	int ba = 0;
	int others = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (islower(arr[i]))
		{
			sa++;
		}
		else if (isupper(arr[i]))
		{
			ba++;
		}
		else if (isdigit(arr[i]))
		{
			num++;
		}
		else {
			others++;
		}
	}

	cout << "数字个数" << num << "\n";
	
	cout << "小写字母个数" << sa;
	cout << "\n";
	cout << "大写字母个数" << ba;
	cout << "\n";
	cout << "其他字符个数" << others;
	cout << "\n";
	return 0;
}