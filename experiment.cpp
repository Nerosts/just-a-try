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
//    cout << "������10���������ƣ�" << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << "���� " << i + 1 << ": ";
//        char input[100];
//        cin >> input;
//        countries[i] = (char*)malloc(sizeof(char*));
//        strcpy(countries[i], input);
//    }
//
//    sortCountries(countries, 10);
//
//    cout << "�����Ĺ������ƣ�" << endl;
//    for (int i = 0; i < 10; i++) {
//        cout << countries[i] << endl;
//    }
//
//    return 0;
//}

int main()
{
	char arr[10] = "abcd  3";
	cout << "������һ���ַ���";
	
	cin.getline(arr, 10);
	cout << "�ַ����ܳ���" << strlen(arr) << "\n";
	
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

	cout << "���ָ���" << num << "\n";
	
	cout << "Сд��ĸ����" << sa;
	cout << "\n";
	cout << "��д��ĸ����" << ba;
	cout << "\n";
	cout << "�����ַ�����" << others;
	cout << "\n";
	return 0;
}