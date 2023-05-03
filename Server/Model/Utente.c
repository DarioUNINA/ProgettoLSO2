#include "Utente.h"

utente* newUtente(char* username, char* password){
    utente* u = (utente*)malloc(sizeof(utente));
    u->username = username;
    u->password = password;
    return u;
}