#include "friendAdmin.h"



char* SearchUser(char* msg){

    char* username = getNewToken(&msg);

    char* s1 = "SELECT * FROM utenti WHERE nome_utente = '";
    char* s2 = "'";

    char* strings[] = {s1, username, s2, NULL};

    if(PQntuples(runQuery(strings))>0)
        return strcat(username, "$$");
    else
        return "error$$";

}

char* AddFriend(char* msg){

    char* username = getNewToken(&msg);
    char* friend = getNewToken(&msg);

    char *s1 = "SELECT * FROM richieste_amicizia WHERE (id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s2 = "') AND id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s3 = "')) OR (id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s4 = "') AND id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s5 = "'))";

    char *strings[] = {s1, username, s2, friend, s3, username, s4, friend, s5, NULL};

    PGresult* res = runQuery(strings);

    if(PQntuples(res) > 0)
        return "error$$";

    s1 = "INSERT INTO richieste_amicizia (id_utente1, id_utente2) VALUES ((SELECT id_utente FROM utenti WHERE nome_utente = '";
    s2 = "'), (SELECT id_utente FROM utenti WHERE nome_utente = '";
    s3 = "'))";
    
    char *strings2[] = {s1, username, s2, friend, s3, NULL};

    if(PQresultStatus(runQuery(strings2)) == PGRES_COMMAND_OK)
        return "ok$$";
    else
        return "error2$$";

}

char* RemoveFriend(char* msg){

    char* username = getNewToken(&msg);
    char* friend = getNewToken(&msg);

    char *s1 = "DELETE FROM amici WHERE (id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s2 = "') AND id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s3 = "')) OR (id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s4 = "') AND id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s5 = "'))";

    char *strings[] = {s1, username, s2, friend, s3, username, s4, friend, s5, NULL};

    if(PQresultStatus(runQuery(strings)) == PGRES_COMMAND_OK)
        return "ok$$";
    else
        return "error$$";

}

char* ShowFriends(char* msg){
    
    char* username = getNewToken(&msg);

    char *s1 = "SELECT nome_utente FROM utenti WHERE id_utente IN (SELECT id_utente2 FROM amici WHERE id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s2 = "')) OR id_utente IN (SELECT id_utente1 FROM amici WHERE id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s3 = "'))";

    char *strings[] = {s1, username, s2, username, s3, NULL};

    PGresult *res = runQuery(strings);

    if(PQresultStatus(res) == PGRES_TUPLES_OK){

        char* result = (char*)malloc(sizeof(char)*1000);

        for(int i = 0; i < PQntuples(res); i++){
            strcat(result, PQgetvalue(res, i, 0));
            strcat(result, "$$");
        }

        return result;
    }else
        return "error$$";
    
}

char* ShowFriendRequests(char* msg){

    char* username = getNewToken(&msg);

    char *s1 = "SELECT nome_utente FROM utenti WHERE (id_utente IN (SELECT id_utente2 FROM richieste_amicizia WHERE id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s2 = "')) OR id_utente IN (SELECT id_utente1 FROM richieste_amicizia WHERE id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s3 = "')))";

    char *strings[] = {s1, username, s2, username, s3, NULL};

    PGresult *res = runQuery(strings);

    if(PQresultStatus(res) == PGRES_TUPLES_OK){

        char* result = (char*)malloc(sizeof(char)*1000);

        for(int i = 0; i < PQntuples(res); i++){
            strcat(result, PQgetvalue(res, i, 0));
            strcat(result, "$$");
        }

        printf("result: %s", result);

        return result;
    }else
        return "error$$";
}

void AcceptFriendRequest(char* msg){

    char* username = getNewToken(&msg);
    char* friend = getNewToken(&msg);

    char *s1 = "INSERT INTO amici (id_utente1, id_utente2) VALUES ((SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s2 = "'), (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char *s3 = "'))";

    char *strings[] = {s1, username, s2, friend, s3, NULL};

    s1 = "DELETE FROM richieste_amicizia WHERE (id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    s2 = "') AND id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    s3 = "')) OR (id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s4 = "') AND id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s5 = "'))";


    char* strings2[] = {s1, friend, s2, username, s3, friend, s4, username, s5, NULL};

    if(PQresultStatus(runQuery(strings)) == PGRES_COMMAND_OK && PQresultStatus(runQuery(strings2)) == PGRES_COMMAND_OK)
        printf("tutto ok\n");
    else
        printf("errore\n");
}

void RejectFriendRequest(char* msg){

    char* username = getNewToken(&msg);
    char* friend = getNewToken(&msg);

    char* s1 = "DELETE FROM richieste_amicizia WHERE (id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s2 = "') AND id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "')) OR (id_utente2 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s4 = "') AND id_utente1 = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s5 = "'))";


    char* strings2[] = {s1, friend, s2, username, s3, friend, s4, username, s5, NULL};

    if(PQresultStatus(runQuery(strings2)) == PGRES_COMMAND_OK)
        printf("tutto ok\n");
    else
        printf("errore\n");
}


void* friendAdmin(void* friendAdminQueue){
    
    CQueue* queue = (CQueue*)friendAdminQueue;
    char *msg, *command, *ip, *result="", output[1000] = "answer$$";

    while(1){
        pthread_mutex_lock(&friendAdminMutex);
        
        if(!cqueue_is_empty(queue)){

            msg  = (char*)cqueue_pop(queue);
            pthread_mutex_unlock(&friendAdminMutex);

            command = getNewToken(&msg);
            ip = getNewToken(&msg);

            if(strcmp(command, "SearchUser") == 0){
                result = SearchUser(msg);
            }

            if(strcmp(command, "AddFriend") == 0){
                result = AddFriend(msg);
            }
            
        }
        pthread_mutex_unlock(&friendAdminMutex);
    }
}