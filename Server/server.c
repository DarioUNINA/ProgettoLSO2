#include "server.h"


void recieveData(int mySocket){
    int clientSocket;
    struct sockaddr_in clientAddr;
    int len = sizeof(clientAddr);
    char msg[DIMBUFF];

    while(1){

        clientSocket = accept(mySocket, (struct sockaddr*)&clientAddr, (socklen_t*)&len);

        if (clientSocket < 0) {
            printf("Server accept failed...\n");

        }else{
            printf("Client accepted... \n");

            read(clientSocket, msg, sizeof(msg));
            executeCommand(msg);
        }
    }
}

void startThreads(){
    
    pthread_create(&utenteThread, NULL, utenteController, NULL);
    pthread_create(&ordineThread, NULL, ordineController, NULL);
    pthread_create(&ordinazioneThread, NULL, ordinazioneController, NULL);
    pthread_create(&bevandaThread, NULL, bevandaController, NULL);

    pthread_join(utenteThread, NULL);
    pthread_join(ordineThread, NULL);
    pthread_join(ordinazioneThread, NULL);
    pthread_join(bevandaThread, NULL);
}


void init(){

    utenteQueue = cqueue_new();
    ordineQueue = cqueue_new();
    ordinazioneQueue = cqueue_new();
    bevandaQueue = cqueue_new();

    getDBConnection();
    startThreads();
}


void start(){                                                           

    init();
    recieveData(getSocket());

}


int main(int argc, char *argv[]){

    start();
    return 0;
}
