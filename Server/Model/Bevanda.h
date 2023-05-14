#ifndef BEVANDA_H
#define BEVANDA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct bevanda{
    char* nome;
    char* descrizione;
    float prezzo;
    char* categoria;
} bevanda;

bevanda* newBevanda(char* nome, char* descrizione, float prezzo, char* categoria);

char* serializeBevanda(bevanda* b);

bevanda* deserializeBevanda(char* stringa);

#endif