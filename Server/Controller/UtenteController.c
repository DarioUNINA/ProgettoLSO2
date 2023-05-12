#include "UtenteController.h"

void* utenteController(){
    char *msg, *command, *result;

    int socket;

    while(1){
        pthread_mutex_lock(&utenteMutex);
        
        if(!cqueue_is_empty(utenteQueue)){
            
            msg  = (char*)cqueue_pop(utenteQueue);
            socket  = (int)cqueue_pop(utenteQueue);
            pthread_mutex_unlock(&utenteMutex);
                
            command = strtok(NULL, "$$");

            // if(strcmp(command, "SearchUser") == 0){ //scrivere comandi
            //     result = SearchUser(msg);
            // }
            
        }
        pthread_mutex_unlock(&utenteMutex);
    }   
}