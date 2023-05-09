#ifndef UTENTE_H
#define UTENTE_H

#include <stdlib.h>

typedef struct utente{
    char* username;
    char* password;
}utente;

utente* newUtente(char* username, char* password);

char* serializeUtente(utente* u);

utente* deserializeUtente(char* stringa);


#endif