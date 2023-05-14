#include <pthread.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 800
#define PORT 8080
#define SA struct sockaddr



int main()
{
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
	else
		printf("Socket successfully created..\n");

	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("192.168.1.54");
	servaddr.sin_port = htons(PORT);

	// connect the client socket to server socket
	while((connect(sockfd, (SA*)&servaddr, sizeof(servaddr))!=0)){}


	// function for chat
	// char buff[MAX] = "ordine$$getCarrello$$Dario$$123";
	// char buff[MAX] = "utente$$registrazione$$Mario$$123";
	char buff[MAX] = "utente$$getUtente$$Mario$$123";

	write(sockfd, buff, sizeof(buff));

	    // lettura della risposta del server
    read(sockfd, buff, sizeof(buff));
    printf("Ho ricevuto: %s\n", buff);
	close(sockfd);

	return 0;
	
}
