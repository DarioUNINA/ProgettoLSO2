#include "BevandaRepository.h"

void getBevande(char* utente, char* result){
    char* strings[6];
    strings[0] = "select distinct  nome, descrizione, prezzo, categoria from ((select * from ordine o join ordinazione ord on o.id_ordine = ord.id_ordine where utente = '"; 
    strings[1] = utente;
    strings[2] = "') as temp join bevanda b on temp.bevanda = b.nome ) union all ((select  * from bevanda) except (select distinct  nome, descrizione, prezzo, categoria from ((select * from ordine o join ordinazione ord on o.id_ordine = ord.id_ordine where utente = '";
    strings[3] = utente;
    strings[4] = "') as temp join bevanda b on temp.bevanda = b.nome )))";
    strings[5] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
        return NULL;
    }

    int rows = PQntuples(res);
    int columns = PQnfields(res);

    for(int i=0; i<PQntuples(res); i++){ //costruire le bevande
        // result = strcat(result, PQgetvalue(res, i, 0));
        // result = strcat(result, "$$");
    }
}