/*
 * Address.cpp
 *
 *  Created on: Feb 21, 2016
 *      Author: werner
 */

#include "Address.h"

using namespace std;

Address::Address(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned short port) {
	// TODO Auto-generated constructor stub
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->port = port;
	int binaddr = ( a << 24 ) |  ( b << 16 ) |  ( c << 8 ) |  d;

	myaddr.sin_family=AF_INET;
	myaddr.sin_addr.s_addr=htonl(binaddr);
	myaddr.sin_port=htons(port);
}

std::string Address::GetAddress()	{
	std::stringstream ss;
	ss << GetA();
	ss << ".";
	ss << GetB();
	ss << ".";
	ss << GetC();
	ss << ".";
	ss << GetD();
	this->address = ss.str();
	return ss.str();
}
