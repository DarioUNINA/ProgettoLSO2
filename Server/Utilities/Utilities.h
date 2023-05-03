#ifndef UTILITIES_H
#define UTILITIES_H

#define DIMBUFF 200

// typedef struct utente{
//     char* username;
//     char* password;
// }utente;

// typedef struct bevanda{
//     char* nome;
//     char* descrizione;
//     float prezzo;
//     char* categoria;
// }bevanda;

// typedef struct ordine{
//     unsigned int idOrdine;
//     char* utente;
//     unsigned short chiuso;
// }ordine;

// typedef struct ordineazione{
//     unsigned int idOrdine;
//     bevanda bevande[100];
// }ordinazione;

#include "postgresql/libpq-fe.h"
#include "../cqueue.h"
#include "../Server/linkedList.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

utente* getUtente();

static int blah = 0;



char* getNewToken(char** string);

int connectSocket(int mySocket, struct sockaddr_in serverAddr);

int getSocket(int server, char* ip);

#endif