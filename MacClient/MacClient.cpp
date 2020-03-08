#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "cursordata.hpp"

#define PORT 42069

int main(int argc, char const *argv[])
{
	int sock = 0, serverReturn;
	struct sockaddr_in serv_addr;
	char buffer[512] = {0};
	char hello[] = "Hello from client";

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "10.10.5.148", &serv_addr.sin_addr) <= 0)
	{
		printf("\n Invalid address/Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\n Connection Failed \n");
		return -1;
	}
	for(;;)
	{
	
		Coordinates data = mousecoordinate();
		char coor[3] = {data.x, data.y, NULL};
		if (data.x < 0)
		{
			break;
		}
		send(sock,coor, 512,0);
		printf("Sent: %d, %d\n", coor[0], coor[1]);
		//printf("int: %d, %d\n", data.x, data.y);
		printf("%s",buffer);
	}
	return 0;
}

