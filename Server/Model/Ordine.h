#ifndef ORDINE_H
#define ORDINE_H

#include <stdlib.h>
#include "Bevanda.h"
#include "../Utilities/cqueue.h"


typedef struct ordine{
    unsigned int idOrdine;
    char* utente;
    unsigned short chiuso;
    CQueue* bevande;
}ordine;

ordine* newOrdine(unsigned int idOrdine, char* utente, unsigned short chiuso, CQueue* bevande);

char* serializeOrdine(ordine* o);

ordine* deserializeOrdine(char* stringa);

#endif