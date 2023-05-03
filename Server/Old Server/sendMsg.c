#include "sendMsg.h"

void sendAnswer(char* msg){
    
    char* ip = getNewToken(&msg);
    
    int socket = getSocket(2, ip);

    if(socket== -1)
        perror("Unable to connect to client");
    else
        write(socket, msg, strlen(msg));

    close(socket);
}


void SendMessage(char* msg){

    char* sender = getNewToken(&msg);
    char* groupName = getNewToken(&msg);
    char* data = getNewToken(&msg);

    int i = 0;

    char* s1 = "SELECT nome_utente FROM utenti WHERE id_utente IN (SELECT id_utente FROM membri WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "')) AND nome_utente != '";
    char* s3 = "'";

    char* strings[] = {s1, groupName, s2, sender, s3, NULL};

    PGresult *res = runQuery(strings);

    for(i = 0; i < PQntuples(res); i++){
        char* reciever = PQgetvalue(res, i, 0);
        
        client c;
        c.username = reciever;
        node* clientFound= find(clients, c);

        if(clientFound==NULL)
            continue;

        int socket = getSocket(1, clientFound->key.ip);

        char* message = (char*)malloc(sizeof(char)*1000); 
        strcat(strcat(strcat(strcat(strcat(groupName, "$$"), sender), "$$"), data), "$$");

        if(socket== -1)
            perror("Unable to connect to client");
        else
            write(socket, message, strlen(message));

        close(socket);
    }
}


void* sendMsg(){

    char *msg, *command, *ip, *result;

    while(1){
        pthread_mutex_lock(&msgSenderMutex);
        
        if(!cqueue_is_empty(msgSenderQueue)){

            msg = (char*)cqueue_pop(msgSenderQueue);
            pthread_mutex_unlock(&msgSenderMutex);

            command = getNewToken(&msg);

            if(strcmp(command, "answer")==0){
                sendAnswer(msg);
            }

            if(strcmp(command, "SendMessage")==0){
                SendMessage(msg);
            }

        }


        pthread_mutex_unlock(&msgSenderMutex);

    }
}