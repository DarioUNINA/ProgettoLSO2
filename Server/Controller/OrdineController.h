#ifndef ORDINECONTROLLER_H
#define ORDINECONTROLLER_H

#include "../Repository/OrdineRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"

CQueue* ordineQueue;
pthread_mutex_t ordineMutex;
extern CQueue* serverQueue;

void* ordineController();

#endif