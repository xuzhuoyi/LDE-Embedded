/*
 * LFCloud.cpp
 *
 *  Created on: 2015-6-7
 *      Author: zhuoyi
 */

#include "LFCloud.h"

#include <stdio.h>    // printf
#include <stdlib.h>    // exit
#include <string.h>    // bzero
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "104.194.77.197"
#define SERVER_PORT 9000
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

LFCloud::LFCloud() {
	// TODO Auto-generated constructor stub

}

LFCloud::~LFCloud() {
	// TODO Auto-generated destructor stub
}

int LFCloud::initCloud()
{
    printf("LDE Frameworks Cloud 0.1.0\nCopyright 2014-2015 LDE Team\n");


    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htons(INADDR_ANY);
    client_addr.sin_port = htons(0);

    // 创建socket，若成功，返回socket描述符
    client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket_fd < 0)
    {
        perror("Create Socket Failed:");
        exit(1);
    }

    // 绑定客户端的socket和客户端的socket地址结构 非必需
    if(-1 == (bind(client_socket_fd, (struct sockaddr*)&client_addr, sizeof(client_addr))))
    {
        perror("Client Bind Failed:");
        exit(1);
    }
return 0;
}

int LFCloud::connectCloud()
{
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if(inet_pton(AF_INET, SERVER_IP , &server_addr.sin_addr) == 0)
    {
        perror("Server IP Address Error:");
        exit(1);
    }
    server_addr.sin_port = htons(SERVER_PORT);
    socklen_t server_addr_length = sizeof(server_addr);

    // 向服务器发起连接，连接成功后client_socket_fd代表了客户端和服务器的一个socket连接
    if(connect(client_socket_fd, (struct sockaddr*)&server_addr, server_addr_length) < 0)
    {
        perror("Can Not Connect To Server IP:");
        exit(0);
    }
return 0;
}

int LFCloud::sendCommand(char *file_name)
{
    // 输入文件名 并放到缓冲区buffer中等待发送
    //char file_name[FILE_NAME_MAX_SIZE+1];
    //bzero(file_name, FILE_NAME_MAX_SIZE+1);
    //printf("Please Input the URL of file:\t");
    //scanf("%s", file_name);

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    strncpy(buffer, file_name, strlen(file_name)>BUFFER_SIZE?BUFFER_SIZE:strlen(file_name));

    // 向服务器发送buffer中的数据
    if(send(client_socket_fd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Send File Name Failed:");
        exit(1);
    }
/*
    bzero(file_name, FILE_NAME_MAX_SIZE+1);
    printf("Please Input File Name On Server:\t");
   scanf("%s", file_name);

    bzero(buffer, BUFFER_SIZE);
    strncpy(buffer, file_name, strlen(file_name)>BUFFER_SIZE?BUFFER_SIZE:strlen(file_name));

    // 向服务器发送buffer中的数据
    if(send(client_socket_fd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Send File Name Failed:");
        exit(1);
    }

    // 打开文件，准备写入
  FILE *fp = fopen(file_name, "w");
  if(NULL == fp)
  {
    printf("File:\t%s Can Not Open To Write\n", file_name);
    exit(1);
  }
*/
  // 从服务器接收数据到buffer中
  // 每接收一段数据，便将其写入文件中，循环直到文件接收完并写完为止
  bzero(buffer, BUFFER_SIZE);
  size_t length = 0;
  while((length = (size_t)recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) > 0)
  {
    printf("%s",buffer);
    bzero(buffer, BUFFER_SIZE);
  }

  // 接收成功后，关闭文件，关闭socket
  printf("\nReceive result of %s From Server IP Successful!\n", file_name);

  //fclose(fp);
  close(client_socket_fd);

  return 0;
}

