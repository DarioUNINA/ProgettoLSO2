#include "OrdinazioneController.h"

void* ordinazioneController(){
    
    char *msg, *command, *result;

    int socket;

    while(1){
        pthread_mutex_lock(&ordinazioneMutex);
        
        if(!cqueue_is_empty(ordinazioneQueue)){
            
            msg  = (char*)cqueue_pop(ordinazioneQueue);
            socket  = (int)cqueue_pop(ordinazioneQueue);
            pthread_mutex_unlock(&ordinazioneMutex);
                
            command = strtok(NULL, "$$");

            // if(strcmp(command, "SearchUser") == 0){ //scrivere comandi
            //     result = SearchUser(msg);
            // }
            
        }
        pthread_mutex_unlock(&ordinazioneMutex);
    }
}