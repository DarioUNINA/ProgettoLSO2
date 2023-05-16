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


void addBevandaToOrdine(char* bevanda, char* username){
    char* strings[6];
    strings[0] = " select id_ordine from ordine where utente = '";
    strings[1] = username;
    strings[2] = "' and chiuso = false";
    strings[3] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }


    strings[0] = "insert into ordinazione values (";
    strings[1] = PQgetvalue(res, 0, 0);
    strings[2] = ", '";
    strings[3] = bevanda;
    strings[4] = "')";
    strings[5] = NULL;

    res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }else
        printf("Bevanda aggiunta a ordine\n");


}

void removeBevandaFromOrdine(char* bevanda, char* username){
    char* strings[6];
    strings[0] = " select id_ordine from ordine where utente = '";
    strings[1] = username;
    strings[2] = "' and chiuso = false";
    strings[3] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }


    strings[0] = "delete from ordinazione where id_ordine =";
    strings[1] = PQgetvalue(res, 0, 0);
    strings[2] = " and bevanda = '";
    strings[3] = bevanda;
    strings[4] = "'";
    strings[5] = NULL;

    res = runQuery(strings);

        if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }else
        printf("Bevanda rimossa dall'ordine\n");


}

void chiudiOrdine(char* username){
    char* strings[4];
    strings[0] = "select id_ordine from ordine where utente = '";
    strings[1] = username;
    strings[2] = "' and chiuso = false";
    strings[3] = NULL;

    PGresult* res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_TUPLES_OK){
        printf("No data retrieved\n");
        PQclear(res);
    }

    strings[0] = "update ordine set chiuso = true where id_ordine = ";
    strings[1] = PQgetvalue(res, 0, 0);
    strings[2] = NULL;

    res = runQuery(strings);

    if (PQresultStatus(res) != PGRES_COMMAND_OK){
        printf("Ordine non chiuso\n");
        PQclear(res);
    }else{
        printf("Ordine chiuso, username vale %s\n", username);

        strings[0] = "insert into ordine (id_ordine, utente, chiuso) values (nextval('id_ordine_seq'), '";
        strings[1] = username;
        strings[2] = "', false)";
        strings[3] = NULL;

        res = runQuery(strings);

        if (PQresultStatus(res) != PGRES_COMMAND_OK){
            printf("Carrello non creato\n");
            PQclear(res);
        }else
            printf("Carrello creato\n");
    }

}