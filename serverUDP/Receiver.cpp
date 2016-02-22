//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h>
//#include <iomanip>
//#include <iostream>
//#include <string.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//int main(void){
//	unsigned int a = 127;
//	unsigned int b = 0;
//	unsigned int c = 0;
//	unsigned int d = 1;
//	unsigned short port = 1234;
//	unsigned int address = ( a << 24 ) |  ( b << 16 ) |  ( c << 8 ) |  d;
//	sockaddr_in myaddr;
//	int sock;
//	//memset(&myaddr, 0, sizeof(myaddr));
//	myaddr.sin_family=AF_INET;
//	myaddr.sin_addr.s_addr=htonl(address);
//	myaddr.sin_port=htons(port);
//
//	//Create the socket
//	if((sock=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))<0) {
//		perror("Failed to create socket");
//		exit(EXIT_FAILURE);
//	}
//
//
//	if(bind(sock,( struct sockaddr *) &myaddr, sizeof(myaddr))<0) {
//		perror("bind failed");
//		exit(EXIT_FAILURE);
//	}
//
//	inet_pton(AF_INET,"127.0.0.1",&myaddr.sin_addr.s_addr);
//	myaddr.sin_port=htons(1234);
//
//	//Receive the datagram back from server
//	int addrLength(sizeof(myaddr)),received(0);
//	char buffer[2560] = {0};
//	int i = 1;
//	std::cout << "Recebendo dados do cliente..." << std::endl;
//	while(true){
//		if((received=recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr *)&myaddr,(socklen_t*)&addrLength) < 0)) {
//			std::cout << "Erro na recepcao do pacote!" << std::endl;
//			perror("Mismatch in number of bytes received");
//			exit(EXIT_FAILURE);
//		}
//		std::cout << i << " RECEBIDO: " << buffer << std::endl;
//		//buffer[received]='\0';
//		i++;
//	}
//	close(sock);
//	std::cout << "Close socket!" << std::endl;
//	return 0;
//}

#include "Socket.h"
#include "Address.h"
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	Socket socket;
	Address address(127,0,0,1,1234);

	if(socket.Open(address)){
		cout << "TRUE!" << endl;
	}
	char * data = {0};
	while(true){
		data = socket.Receive(address,data);
		cout << "Recebido" << endl;
	}
}
