#ifndef SERVER_H
#define SERVER_H

#include "Controller/BevandaController.h"
#include "Controller/OrdineController.h"
#include "Controller/UtenteController.h"
#include "Controller/OrdinazioneController.h"
#include "Repository/DataBase.h"
#include "Utilities/cqueue.h"
#include "Utilities/Utilities.h"
#include "sys/socket.h"


pthread_t utenteThread;
pthread_t ordineThread;
pthread_t ordinazioneThread;
pthread_t bevandaThread;

extern CQueue* utenteQueue;
extern CQueue* ordineQueue;
extern CQueue* ordinazioneQueue;
extern CQueue* bevandaQueue;

CQueue* serverQueue;

void recieveData(int mySocket);

void startThreads();

void start();

void init();



#endif