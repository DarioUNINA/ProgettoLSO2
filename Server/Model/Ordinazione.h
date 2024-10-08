#ifndef ORDINAZIONE_H
#define ORDINAZIONE_H

#include <stdlib.h>

typedef struct ordinazione{
    unsigned int idOrdine;
    char** bevande;
}ordinazione;

ordinazione* newOrdinazione(unsigned int idOrdine, char** bevande);

char* serializeOrdinazione(ordinazione* o);

ordinazione* deserializeOrdinazione(char* stringa);


#endif