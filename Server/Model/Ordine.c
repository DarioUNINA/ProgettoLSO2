#include "Ordine.h"

ordine* newOrdine(unsigned int idOrdine, char* utente, unsigned short chiuso){
    ordine* o = (ordine*)malloc(sizeof(ordine));
    o->idOrdine = idOrdine;
    o->utente = utente;
    o->chiuso = chiuso;
    return o;
}