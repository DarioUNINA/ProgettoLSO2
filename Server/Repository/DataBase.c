#include "DataBase.h"

void getDBConnection(){
    connectionMutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}