#include "Bevanda.h"

bevanda* newBevanda(char* nome, char* descrizione, float prezzo, char* categoria){
    bevanda* b = (bevanda*)malloc(sizeof(bevanda));
    b->nome = nome;
    b->descrizione = descrizione;
    b->prezzo = prezzo;
    b->categoria = categoria;
    return b;
}

char* serializeBevanda(bevanda* b){
    char* result = malloc(256 * sizeof(char));

    sprintf(result, "{\"nome\" : \"%s\", \"descrizione\" : \"%s\", \"prezzo\" : \"%f\", \"categoria\" : \"%s\"}", b->nome, b->descrizione, b->prezzo, b->categoria);

    return result;
}

