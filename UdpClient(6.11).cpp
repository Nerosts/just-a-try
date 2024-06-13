#define _CRT_SECURE_NO_WARNINGS 1
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<Windows.h>

using namespace std;

#pragma comment(lib,"ws2_32.lib")//链接这个包
#pragma warning(disable:4996)

string serverip = "47.120.42.50";
uint16_t serverport = 8888;

int main()
{
	std::cout << "hello client" << std::endl;
	WSADATA wsd;//定义变量
	WSAStartup(MAKEWORD(2,2), &wsd);//进行初始化,第一个参数是选择版本号

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0); // 套接字
    if (sockfd ==SOCKET_ERROR)
    {
        cout << "socker error" << endl;
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);                  // 转成网络序列
    server.sin_addr.s_addr = inet_addr(serverip.c_str()); // 套接字结构体

    // client 要bind吗？要！只不过不需要用户显示的bind！一般有OS自由随机选择！
    // 我们平时也都是手机用户，每次启动app，请求服务都是OS进行的
    // 其实client的port是多少，其实不重要，只要能保证主机上的唯一性就可以！
    // 系统什么时候给我bind呢？首次发送数据的时候

    string message;
    char ret[1024];
    while (true)
    {
        cout << "Please Enter@ ";
        getline(cin, message);
        // 发什么内容？？ 给谁发？？
        sendto(sockfd, message.c_str(), (int)message.size(), 0, (const struct sockaddr*)&server, (int)sizeof(server));

        // 拿到回信就行,不会再用
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