#define _CRT_SECURE_NO_WARNINGS 1
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<Windows.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")//���������
#pragma warning(disable:4996)

string serverip = "47.120.42.50";
uint16_t serverport = 8888;

int main()
{
	std::cout << "hello client" << std::endl;
	WSADATA wsd;//�������
	WSAStartup(MAKEWORD(2,2), &wsd);//���г�ʼ��,��һ��������ѡ��汾��

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0); // �׽���
    if (sockfd ==SOCKET_ERROR)
    {
        cout << "socker error" << endl;
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);                  // ת����������
    server.sin_addr.s_addr = inet_addr(serverip.c_str()); // �׽��ֽṹ��

    // client Ҫbind��Ҫ��ֻ��������Ҫ�û���ʾ��bind��һ����OS�������ѡ��
    // ����ƽʱҲ�����ֻ��û���ÿ������app�����������OS���е�
    // ��ʵclient��port�Ƕ��٣���ʵ����Ҫ��ֻҪ�ܱ�֤�����ϵ�Ψһ�ԾͿ��ԣ�
    // ϵͳʲôʱ�����bind�أ��״η������ݵ�ʱ��

    string message;
    char ret[1024];
    while (true)
    {
        cout << "Please Enter@ ";
        getline(cin, message);
        // ��ʲô���ݣ��� ��˭������
        sendto(sockfd, message.c_str(), (int)message.size(), 0, (const struct sockaddr*)&server, (int)sizeof(server));

        // �õ����ž���,��������
        struct sockaddr_in temp;
        int len = sizeof(temp);

        int s = recvfrom(sockfd, ret, 1023, 0, (struct sockaddr*)&temp, &len);
        if (s > 0)
        {
            ret[s] = 0;
            cout << ret << endl;
        }
    }
    closesocket(sockfd);

	WSACleanup();
	return 9;
}