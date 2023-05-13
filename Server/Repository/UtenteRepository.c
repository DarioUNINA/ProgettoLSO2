#include "UtenteRepository.h"

void getUtente(char* username, char* password, char* result){
    char* strings[6];
    strings[0] = "SELECT * FROM utente WHERE username = '";
    strings[1] = username;
    strings[2] = "' AND password = '";
    strings[3] = password;
    strings[4] = "'";
    strings[5] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
        return NULL;
    }

    int rows = PQntuples(res);
    int columns = PQnfields(res);

    if(rows == 0){
        printf("Nessun utente trovato\n");
        PQclear(res);
        strcat(result,"false");
    }else{
        printf("Utente trovato\n");
        strcat(result,"true");
    }

}