#ifndef UTENTEREPOSITORY_H
#define UTENTEREPOSITORY_H

#include "DataBase.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

char* getUtente(char* username, char* password);


#endif