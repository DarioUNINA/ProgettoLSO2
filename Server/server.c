#include "server.h"


void receiveData(int mySocket){
    int clientSocket;
    struct sockaddr_in clientAddr;
    int len = sizeof(clientAddr);
    char * msg = malloc(sizeof(char)*DIMBUFF);

    while(1){

        clientSocket = accept(mySocket, (struct sockaddr*)&clientAddr, (socklen_t*)&len);

        if (clientSocket < 0) {
            printf("Server accept failed...\n");

        }else{
            printf("Client accepted... \n");

            read(clientSocket, msg, DIMBUFF);

            char* command = strtok(msg, "$$");

            if(strcmp(command, "bevanda")==0){
                pthread_mutex_lock(&bevandaMutex);
                cqueue_push(bevandaQueue, msg);
                cqueue_push(bevandaQueue,clientSocket);
                pthread_mutex_unlock(&bevandaMutex);
            }

            if(strcmp(command, "utente")==0){
                pthread_mutex_lock(&utenteMutex);
                cqueue_push(utenteQueue, msg);
                cqueue_push(utenteQueue,clientSocket);
                pthread_mutex_unlock(&utenteMutex);
            }

            if(strcmp(command, "ordinazione")==0){
                pthread_mutex_lock(&ordinazioneMutex);
                cqueue_push(ordinazioneQueue, msg);
                cqueue_push(ordinazioneQueue,clientSocket);
                pthread_mutex_unlock(&ordinazioneMutex);
            }

            if(strcmp(command, "ordine")==0){
                pthread_mutex_lock(&ordineMutex);
                cqueue_push(ordineQueue, msg);
                cqueue_push(ordineQueue,clientSocket);
                pthread_mutex_unlock(&ordineMutex);
            }

        }
    }

    free(msg);
}


void startThreads(){
    
    pthread_create(&utenteThread, NULL, utenteController, NULL);
    pthread_create(&ordineThread, NULL, ordineController, NULL);
    pthread_create(&ordinazioneThread, NULL, ordinazioneController, NULL);
    pthread_create(&bevandaThread, NULL, bevandaController, NULL);


    pthread_detach(utenteThread);
    pthread_detach(ordineThread);
    pthread_detach(ordinazioneThread);
    pthread_detach(bevandaThread);

}


void init(){

    utenteQueue = cqueue_new();
    ordineQueue = cqueue_new();
    ordinazioneQueue = cqueue_new();
    bevandaQueue = cqueue_new();

    utenteMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    ordineMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    ordinazioneMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    bevandaMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;

    getDBConnection();
    startThreads();
}


void start(){                                                           

    init();
    receiveData(getSocket());

}


int main(int argc, char *argv[]){

    start();
            
    return 0;
}
