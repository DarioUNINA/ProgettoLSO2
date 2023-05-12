#ifndef UTENTECONTROLLER_H
#define UTENTECONTROLLER_H

#include "../Repository/UtenteRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"
#include <unistd.h>

CQueue* utenteQueue;
pthread_mutex_t utenteMutex;
extern CQueue* serverQueue;

void* utenteController();

#endif