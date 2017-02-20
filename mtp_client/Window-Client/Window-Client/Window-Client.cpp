// Window-Client.cpp : Defines the entry point for the console application.
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
#define	connect_timeout		5		

void main_usage() {
	printf("usage: Item Options\n\n");
}


int main(int argc, char *argv[])
{
	WSADATA WsaDat;
	struct sockaddr_in SockAddr;
	char cmd_buf[CMD_BUF_SZ] = { 0 };
	char rev_buf[CMD_BUF_SZ] = { 0 };
	int len;
	int result;
	unsigned int cmd_len = sizeof(cmd_buf) / sizeof(char);
	unsigned int rev_len = sizeof(rev_buf) / sizeof(char);
	//printf("argc=%d\n", argc);
	if ( argc < 2|| !strcmp(argv[1], "-h") || !strcmp(argv[1], "help")) {
		main_usage();
		exit(1);
		return 0;
	}
	
	if (argc == 3)
	{
		strncat_s(cmd_buf, argv[1], strlen((const char *)(argv[1])));
		strncat_s(cmd_buf, " ", 1);
		strncat_s(cmd_buf, argv[2], strlen((const char *)(argv[2])));
		printf("Set CMD=%s\n", argv[1]);
		printf("Set PARAMETER=%s\n", argv[2]);
		
	}
	else if(argc == 2){
		strncat_s(cmd_buf, argv[1], strlen((const char *)(argv[1])));
		printf("Set CMD=%s\n", argv[1]);
	}
	else{
		main_usage();
		exit(1);
		return 0;
	}

	if(WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
	{
		printf("[Client] WSA	Initialization failed.");
	}

	SOCKET sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(sockfd == INVALID_SOCKET)
	{
		printf("[Client] Socket creation failed.");
		exit(1);
	}

	SockAddr.sin_family = AF_INET;
	SockAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
	SockAddr.sin_port = htons(SERVER_PORT);
	len = sizeof(SockAddr);
	struct timeval timeout ;
	fd_set r;

	//NonBlock mode
	unsigned long S_flag = 1;
	ret = ioctlsocket(sockfd, FIONBIO, (unsigned long *)&S_flag);
	if (ret == SOCKET_ERROR)
	{
		printf("[Client] Set to non-blocking mode.Fail");
		closesocket(sockfd);
		exit(1);
	}
	
	connect(sockfd, (struct sockaddr *)&SockAddr, len);
	//Set timeout
	FD_ZERO(&r);
	FD_SET(sockfd,&r);
	timeout.tv_sec = connect_timeout;
	timeout.tv_usec =0;
	result = select(0,0,&r,0,&timeout);
	if (result == -1)
	{
		printf("[Client] Oops: Client connect fail\n");
		closesocket(sockfd);
		system("PAUSE");
		exit(1);
	}
	//Block mode
	S_flag = 0;
	result = ioctlsocket(sockfd, FIONBIO, (unsigned long *)&S_flag);
	if (ret == SOCKET_ERROR)
	{
		printf("[Client] Set to blocking mode.Fail");
		closesocket(sockfd);
		exit(1);
	}
	

	send(sockfd, cmd_buf, cmd_len, 0);
	result=recv(sockfd, rev_buf, rev_len, 0);
	if (result < 0){
		printf("Set %s=FAIL\n", argv[1]);
		printf("Connect FAIL\n");
	}
	else
	printf("Set %s\n", rev_buf);
	//system("PAUSE");
	
    return 0;
}

