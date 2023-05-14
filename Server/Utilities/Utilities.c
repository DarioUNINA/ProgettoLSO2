#include "Utilities.h"




int connectSocket(int mySocket, struct sockaddr_in serverAddr){

	while((bind(mySocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) != 0){}

    printf("Socket successfully binded..\n");

    if ((listen(mySocket, 10)) != 0){
        printf("Listen failed...\n");
        exit(-3);
    }else
        printf("Server listening..\n");

    return mySocket;

}


int getSocket(){

    int mySocket;
	struct sockaddr_in serverAddr;

	// socket create and verification
	mySocket = socket(AF_INET, SOCK_STREAM, 0);

	if (mySocket == -1){
		printf("Socket creation failed...\n");
		exit(-1);
	}else
		printf("Socket successfully created..\n");
	
	// assign IP, PORT
	serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if ((bind(mySocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) != 0){
        printf("Socket bind failed...\n");
        exit(-2);
	}else
		printf("Socket successfully binded..\n");

    if ((listen(mySocket, 10)) != 0){
        printf("Listen failed...\n");
        exit(-3);
    }else
        printf("Server listening..\n");

    return mySocket;

}





