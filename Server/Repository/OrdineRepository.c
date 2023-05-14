#include "OrdineRepository.h"

void getCarrello(char* username, char* result){
    char* strings[4];
    strings[0] = "select bevanda, descrizione, prezzo, categoria from ordine natural join ordinazione ord join bevanda b on ord.bevanda = b.nome WHERE utente = '";
    strings[1] = username;
    strings[2] = "' AND chiuso = false";
    strings[3] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }

    int rows = PQntuples(res);
    int columns = PQnfields(res);

    for(int i = 0; i < rows; i++){ //costruisci il json delle bevande
        bevanda* b = newBevanda(PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), atof(PQgetvalue(res, i, 2)), PQgetvalue(res, i, 3));
        strcat(result, serializeBevanda(b));      
    }

}