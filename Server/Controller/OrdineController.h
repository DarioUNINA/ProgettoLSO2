#ifndef ORDINECONTROLLER_H
#define ORDINECONTROLLER_H

#include "../Repository/OrdineRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"

CQueue* ordineQueue;
extern CQueue* serverQueue;

void* ordineController();

#endif