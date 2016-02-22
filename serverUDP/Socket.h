/*
 * Socket.h
 *
 *  Created on: Feb 21, 2016
 *      Author: werner
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "Address.h"
#include <string>
#include <iostream>

class Socket {
public:
	Socket();
	virtual ~Socket();
	bool Open(Address address);
	void Close();
	bool Send(Address address, const void * data);
	char * Receive(Address sender, char * data);
private:
	int fd;
};

#endif /* SOCKET_H_ */
