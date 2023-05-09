#ifndef UTENTECONTROLLER_H
#define UTENTECONTROLLER_H

#include "../Repository/UtenteRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"

CQueue* utenteQueue;
extern CQueue* serverQueue;

void* utenteController();

#endif