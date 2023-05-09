#ifndef ORDINE_H
#define ORDINE_H

#include <stdlib.h>

typedef struct ordine{
    unsigned int idOrdine;
    char* utente;
    unsigned short chiuso;
}ordine;

ordine* newOrdine(unsigned int idOrdine, char* utente, unsigned short chiuso);

char* serializeOrdine(ordine* o);

ordine* deserializeOrdine(char* stringa);

#endif