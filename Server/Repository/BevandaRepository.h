#ifndef BEVANDAREPOSITORY_H
#define BEVANDAREPOSITORY_H

#include "DataBase.h"
#include "../Model/Bevanda.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

void getBevande(char* utente, char* result);

#endif