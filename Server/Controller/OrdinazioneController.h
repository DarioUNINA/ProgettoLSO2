#ifndef ORDINAZIONECONTROLLER_H
#define ORDINAZIONECONTROLLER_H

#include "../Repository/OrdinazioneRepository.h"
#include "../server.h"
#include "../Utilities/cqueue.h"

CQueue* ordinazioneQueue;
extern CQueue* serverQueue;

void* ordinazioneController();

#endif