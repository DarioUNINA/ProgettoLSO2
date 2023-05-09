#ifndef BEVANDACONTROLLER_H
#define BEVANDACONTROLLER_H

#include "../Repository/BevandaRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"

CQueue* bevandaQueue;
extern CQueue* serverQueue;

void* bevandaController();

#endif