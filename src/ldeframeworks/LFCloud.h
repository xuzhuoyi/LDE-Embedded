/*
 * LFCloud.h
 *
 *  Created on: 2015-6-7
 *      Author: zhuoyi
 */

#ifndef LFCLOUD_H_
#define LFCLOUD_H_

#include <netinet/in.h>  // sockaddr_in

class LFCloud {
public:
	LFCloud();
	virtual ~LFCloud();
	int initCloud();
	int connectCloud();
	int sendCommand(char *file_name);
private:
	// 声明并初始化一个客户端的socket地址结构
	 struct sockaddr_in client_addr;
	 int client_socket_fd;
	 // 声明一个服务器端的socket地址结构，并用服务器那边的IP地址及端口对其进行初始化，用于后面的连接
	    struct sockaddr_in server_addr;
};

#endif /* LFCLOUD_H_ */
