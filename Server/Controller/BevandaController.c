#include "BevandaController.h"

void* bevandaController(){

    char *msg, *command, *result;

    int socket;

    while(1){
        pthread_mutex_lock(&bevandaMutex);
        
        if(!cqueue_is_empty(bevandaQueue)){
            
            msg  = (char*)cqueue_pop(bevandaQueue);
            socket  = (int)cqueue_pop(bevandaQueue);
            pthread_mutex_unlock(&bevandaMutex);
                
            command = strtok(NULL, "$$");

            // if(strcmp(command, "SearchUser") == 0){ //scrivere comandi
            //     result = SearchUser(msg);
            // }
            
        }
        pthread_mutex_unlock(&bevandaMutex);
    }
}   
