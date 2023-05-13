#include "Ordine.h"

ordine* newOrdine(unsigned int idOrdine, char* utente, unsigned short chiuso, CQueue* bevande){
    ordine* o = (ordine*)malloc(sizeof(ordine));
    o->idOrdine = idOrdine;
    o->utente = utente;
    o->chiuso = chiuso;
    o->bevande = bevande;
    return o;
}