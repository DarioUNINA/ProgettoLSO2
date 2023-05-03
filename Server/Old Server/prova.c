#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#include "cqueue.h"

#define PORT 8080
#define SA struct sockaddr
#define DIM 500


int connectSocket(int mySocket, struct sockaddr_in serverAddr){

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


int getSocket(int server, char* ip){

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
	serverAddr.sin_port = htons(PORT);

    if(server){
        serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        return connectSocket(mySocket, serverAddr);

    }else{
        serverAddr.sin_addr.s_addr = inet_addr(ip);
        serverAddr.sin_port = htons(8081);

        while(connect(mySocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr))!= 0){}
        return mySocket;

    }

} 

char* runQuery(char* strings[]){
    int size = 0, i=0, j, k=0;

    while(strings[i] != NULL){
        size+=strlen(strings[i]);
        i++;
    }

    char query[size+1];

    i=0;

    while(strings[i] != NULL){
        j=0;
        while(strings[i][j] != '\0'){
            query[k] = strings[i][j];
            k++;
            j++;
        }
        i++;
    }

    query[k]='\0';


    return query;
}
int main(){
    
    char* strings = {"uno", "due", NULL};

    char query[] = runQuery(strings);

    printf("%s\n", query);
    
    return 0;
}