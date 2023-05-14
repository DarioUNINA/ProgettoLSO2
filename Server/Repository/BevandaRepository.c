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
        return;
    }

    int rows = PQntuples(res), columns = PQnfields(res);

    printf(" ho trovato %d bevande\n", rows);

    for(int i=0; i<PQntuples(res); i++){
        bevanda* b = newBevanda(PQgetvalue(res, i, 0), PQgetvalue(res, i, 1), atof(PQgetvalue(res, i, 2)), PQgetvalue(res, i, 3));
        char* temp = serializeBevanda(b);

        strcat(result, temp);
    }

}


