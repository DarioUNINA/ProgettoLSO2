#include "server.h"

pthread_mutex_t userAdminMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t friendAdminMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t groupAdminMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t msgSenderMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t connectionMutex =  PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t clientsMutex =  PTHREAD_MUTEX_INITIALIZER;


PGresult* runQuery(char* strings[]){    
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

    printf("La query è: %s\n", query);

    pthread_mutex_lock(&connectionMutex);
    PGresult* res = PQexec(connection, query);
    pthread_mutex_unlock(&connectionMutex);

    return res;
}


char* getCommand(char** msg){

    return getNewToken(msg);
}


void executeCommand(char* msg){

    char* command = getCommand(&msg);
    
    if(strcmp(command, "LO")==0){
        char* userName = getNewToken(&msg);
        
        pthread_mutex_lock(&clientsMutex);
        clients = deleteData(clients, userName);
        pthread_mutex_unlock(&clientsMutex);
        
    }

    if(strcmp(command, "UA")==0){
        pthread_mutex_lock(&userAdminMutex);
        cqueue_push(userAdminQueue, msg);
        pthread_mutex_unlock(&userAdminMutex);
    }

    if(strcmp(command, "GA")==0){
        pthread_mutex_lock(&groupAdminMutex);
        cqueue_push(groupAdminQueue, msg);
        pthread_mutex_unlock(&groupAdminMutex);
    }

    if(strcmp(command, "FA")==0){
        pthread_mutex_lock(&friendAdminMutex);
        cqueue_push(friendAdminQueue, msg);
        pthread_mutex_unlock(&friendAdminMutex);
    }

    if(strcmp(command, "SM")==0){
        pthread_mutex_lock(&msgSenderMutex);
        cqueue_push(msgSenderQueue, msg);
        pthread_mutex_unlock(&msgSenderMutex);
    }
    
}


void receiveClientData(int mySocket){

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

    pthread_create(&msgSenderThread, NULL, sendMsg, NULL);
    pthread_detach(msgSenderThread);

    pthread_create(&userAdminThread, NULL, userAdmin, userAdminQueue);
    pthread_detach(userAdminThread);

    pthread_create(&groupAdminThread, NULL, groupAdmin, groupAdminQueue);
    pthread_detach(groupAdminThread);
  
    pthread_create(&friendAdminThread, NULL, friendAdmin, friendAdminQueue);
    pthread_detach(friendAdminThread);
  
}


PGconn* getDBConnection(){
    
    PGconn* conn = PQconnectdb("user=postgres password=password dbname=LSO host=localhost");

    if (PQstatus(conn) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
    }else
        printf("Connection to database successful\n");

    return conn;
}


void init(){

    userAdminQueue = cqueue_new();
    groupAdminQueue = cqueue_new();
    friendAdminQueue = cqueue_new();
    msgSenderQueue = cqueue_new();
    
    clients = getNode();

    connection = getDBConnection();
    startThreads();
}


void start(){

    init();
    receiveClientData(getSocket(0, NULL));

}


// // Driver function
int main(int argc, char *argv[]){

    start();
    return 0;
}
