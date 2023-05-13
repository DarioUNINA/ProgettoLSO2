#include "UtenteController.h"

void* utenteController(){
    char *msg, *command = malloc(sizeof(char)*DIMBUFF), *result = malloc(sizeof(char)*DIMBUFF);

    int socket;

    while(1){
        pthread_mutex_lock(&utenteMutex);
        
        if(!cqueue_is_empty(utenteQueue)){
            
            msg  = (char*)cqueue_pop(utenteQueue);
            socket  = (int)cqueue_pop(utenteQueue);
            pthread_mutex_unlock(&utenteMutex);
                
            command = strtok(NULL, "$$");

            if(strcmp(command, "getUtente") == 0){
                char* username = strtok(NULL, "$$");
                char* password = strtok(NULL, "$$");
                getUtente(username, password, result);
            }

            write(socket, result, DIMBUFF);

        }
        pthread_mutex_unlock(&utenteMutex);
    }   

    free(command);
    free(result);
    pthread_exit(NULL);
}