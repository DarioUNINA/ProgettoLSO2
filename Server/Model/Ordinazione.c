#include "Ordinazione.h"

ordinazione* newOrdinazione(unsigned int idOrdine, char** bevande){
    ordinazione* o = (ordinazione*)malloc(sizeof(ordinazione));
    o->idOrdine = idOrdine;
    o->bevande = bevande;
    return o;
}