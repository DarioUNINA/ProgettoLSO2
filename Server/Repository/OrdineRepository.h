#ifndef ORDINEREPOSITORY_H
#define ORDINEREPOSITORY_H

#include "DataBase.h"
#include "../Model/Ordine.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

void getCarrello(char* username, char* result);

void addBevandaToOrdine(char* bevanda, char* username);

void chiudiOrdine(char* username);


#endif