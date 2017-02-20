// mtp_client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <WinSock2.h>
#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define SERVER_PORT 9734
//#define SERVER_ADDR "192.168.231.131"
#define SERVER_ADDR "10.10.10.6"
#define CMD_BUF_SZ 128

int main(int argc, char *argv[])
{
	WSADATA WsaDat;
	struct sockaddr_in SockAddr;
	char cmd_buf[CMD_BUF_SZ] = { 0 };
	int len;
	int result;
	unsigned int cmd_len = sizeof(cmd_buf)/sizeof(char);

	if (argc>1)
	{
		strncat_s(cmd_buf, "qci_test", 8);

		for (int i = 1; i < argc; i++)
		{
			strncat_s(cmd_buf, " ", 1);
			strncat_s(cmd_buf, argv[i], strlen((const char *)(argv[i])));
		}
		printf("[QCI] cmd_buf[%s]\n", cmd_buf);
	}

	if(WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
	{
		printf("[QCI] WSA	Initialization failed.");
	}

	SOCKET sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sockfd == INVALID_SOCKET)
	{
		printf("[QCI] Socket creation failed.");
		exit(1);
	}

	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	SockAddr.sin_port = htons(SERVER_PORT);
	len = sizeof(SockAddr);
	result = connect(sockfd, (struct sockaddr *)&SockAddr, len);

	if (result == -1)
	{
		printf("[QCI] Oops: Client connect fail\n");
		system("PAUSE");
		exit(1);
	}

	send(sockfd, cmd_buf, cmd_len, 0);
	recv(sockfd, cmd_buf, cmd_len, 0);
	printf("[QCI] Char from server = %s\n", cmd_buf);
	system("PAUSE");
	
    return 0;
}

