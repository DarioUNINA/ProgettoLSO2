#include "Bevanda.h"

bevanda* newBevanda(char* nome, char* descrizione, float prezzo, char* categoria){
    bevanda* b = (bevanda*)malloc(sizeof(bevanda));
    b->nome = nome;
    b->descrizione = descrizione;
    b->prezzo = prezzo;
    b->categoria = categoria;
    return b;
}