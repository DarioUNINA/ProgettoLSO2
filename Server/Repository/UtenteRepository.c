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
        return;
    }

    int rows = PQntuples(res);
    int columns = PQnfields(res);

    if(rows == 0){
        printf("Nessun utente trovato\n");
        PQclear(res);
        strcat(result,"false");
    }else{
        printf("Utente trovato\n");
        PQclear(res);
        strcat(result,"true");
    }

}


void registrazione(char* username, char* password, char* result){
    char* strings[6];
    strings[0] = "INSERT INTO utente VALUES('"; //Crea l'utente
    strings[1] = username;
    strings[2] = "', '";
    strings[3] = password;
    strings[4] = "')";
    strings[5] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_COMMAND_OK ){
        printf("Creazione utente fallita\n");
        PQclear(res);
        return;
    }else
        printf("Utente creato\n");
    

    strings[0] = "insert into ordine values (nextval('id_ordine_seq'), '"; //Crea il carrello
    strings[1] = username;
    strings[2] = "')";
    strings[3] = NULL;

    res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_COMMAND_OK ){
        printf("Creazione ordine fallita\n");
        PQclear(res);
        return;
    }else
        printf("Ordine creato\n");

    free(result);
    strcat(result,"true");

}