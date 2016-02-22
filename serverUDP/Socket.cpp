/*
 * Socket.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: werner
 */

#include "Socket.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

Socket::Socket() {
	// TODO Auto-generated constructor stub

}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

bool Socket::Open(Address address) {
	if((this->fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))<0) {
		return false;
	}else{
		if(bind(this->fd,( struct sockaddr *) &address.GetAddr(), sizeof(address.GetAddr()))<0) {
			std::cout << "Erro no bind" << std::endl;
			return false;
		}
		inet_pton(AF_INET,(const char *)address.GetAddress(),&address.GetAddr().sin_addr.s_addr);
		address.GetAddr().sin_port=htons(1234);
		return true;
	}
}

void Socket::Close() {
	close(this->fd);
}

bool Socket::Send(Address address, const void * data) {
	if(sendto(this->fd, data, sizeof(data), 0, (struct sockaddr *)&address.GetAddr(), sizeof(address.GetAddr()))!=sizeof(data)){
		std::cout << "Erro no envio do pacote!" << std::endl;
		return false;
	}else{
		return true;
	}
}

char * Socket::Receive(Address sender, char * data) {
	int received = 0;
	int addrLength(sizeof(sender.GetAddr()));
	if((received=recvfrom(this->fd, data, sizeof(data), 0, (sockaddr *)&sender.GetAddr(),(socklen_t*)&addrLength)) < 0) {
		std::cout << "Erro na recepcao do pacote!" << std::endl;
		return 0;
	}else{
		return data;
	}
}
