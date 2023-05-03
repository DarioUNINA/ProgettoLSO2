#include "groupAdmin.h"


char* CreateGroup(char* msg){

    char* groupName = getNewToken(&msg);
    char* admin = getNewToken(&msg);

    char* s1 = "INSERT INTO gruppi (id_gruppo, nome_gruppo, id_admin) VALUES (nextval('id_gruppo_seq'), '";
    char* s2 = "', (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "'))";

    char *strings[] = {s1, groupName, s2, admin, s3, NULL};

    if(PQresultStatus(runQuery(strings)) == PGRES_COMMAND_OK){

        s1 = "SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
        s2 = "'";

        char *strings[] = {s1, groupName, s2, NULL};

        char* id_gruppo = PQgetvalue(runQuery(strings), 0, 0);

        s1= "INSERT INTO membri VALUES ('";
        s2 = "', (SELECT id_utente FROM utenti WHERE nome_utente = '";
        s3 = "'))";

        char *strings2[] = {s1, id_gruppo, s2, admin, s3, NULL};

        runQuery(strings2);

        char* s4;

        while(strcmp(s3=getNewToken(&msg), "")!=0 ){
            s1 = "INSERT INTO membri (id_gruppo, id_utente) VALUES ('";
            s2 = "', (SELECT id_utente FROM utenti WHERE nome_utente = '";
            s4 = "'))";

            char *strings3[] = {s1, id_gruppo, s2, s3, s4, NULL};
            runQuery(strings3);
        }

        return "ok$$";
    }
    else
        return "error$$";
}

void DeleteGroup(char* msg){

    char* groupName = getNewToken(&msg);

    char* s1 = "DELETE FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'";

    char *strings[] = {s1, groupName, s2, NULL};

    runQuery(strings);
}

char* SearchGroup(char* msg){

    char* groupName = getNewToken(&msg);

    char* s1 = "SELECT * FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'";

    char *strings[] = {s1, groupName, s2, NULL};

    if(PQntuples(runQuery(strings)) == 0)
        return "error$$";
    else
        return groupName;
}

char* GetGroupMembers(char* msg){

    char* groupName = getNewToken(&msg);

    char* s1 = "SELECT nome_utente FROM utenti WHERE id_utente IN (SELECT id_utente FROM membri WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'))";

    char *strings[] = {s1, groupName, s2, NULL};

    PGresult *res = runQuery(strings);

    char* result = (char*)malloc(sizeof(char)*1000);

    for(int i=0; i<PQntuples(res); i++){
        result = strcat(result, PQgetvalue(res, i, 0));
        result = strcat(result, "$$");
    }

    return result;
}

char* JoinGroup(char* msg){
    char* username = getNewToken(&msg);
    char* groupName = getNewToken(&msg);

    char* s1 = "INSERT INTO richieste_gruppi (id_gruppo, id_utente) VALUES ((SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'), (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "'))";

    char *strings[] = {s1, groupName, s2, username, s3, NULL};

    PGresult* res = runQuery(strings);

    if(PQresultStatus(res) == PGRES_COMMAND_OK)
        return "ok$$";
    else
        return "error$$";
}

void LeaveGroup(char* msg){
    char* username = getNewToken(&msg);
    char* groupName = getNewToken(&msg);

    char* s1 = "DELETE FROM membri WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "') AND id_utente = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "')";

    char *strings[] = {s1, groupName, s2, username, s3, NULL};

    runQuery(strings);
}

char* GetGroupRequests(char* msg){
    char* groupName = getNewToken(&msg);

    char* s1 = "SELECT nome_utente FROM utenti WHERE id_utente IN (SELECT id_utente FROM richieste_gruppi WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'))";

    char *strings[] = {s1, groupName, s2, NULL};

    PGresult *res = runQuery(strings);

    char* result = (char*)malloc(sizeof(char)*1000);

    for(int i=0; i<PQntuples(res); i++){
        result = strcat(result, PQgetvalue(res, i, 0));
        result = strcat(result, "$$");
    }

    return result;
}

void AcceptGroupRequests(char* msg){
    char* groupName = getNewToken(&msg);
    char* username = getNewToken(&msg);

    char* s1 = "INSERT INTO membri (id_gruppo, id_utente) VALUES ((SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "'), (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "'))";

    char *strings[] = {s1, groupName, s2, username, s3, NULL};

    runQuery(strings);

    s1 = "DELETE FROM richieste_gruppi WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    s2 = "') AND id_utente = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    s3 = "')";
    
    char *strings2[] = {s1, groupName, s2, username, s3, NULL};

    runQuery(strings2);
}

void RejectGroupRequests(char* msg){
    char* groupName = getNewToken(&msg);
    char* username = getNewToken(&msg);

    char* s1 = "DELETE FROM richieste_gruppi WHERE id_gruppo = (SELECT id_gruppo FROM gruppi WHERE nome_gruppo = '";
    char* s2 = "') AND id_utente = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s3 = "')";

    char *strings[] = {s1, groupName, s2, username, s3, NULL};

    runQuery(strings);
}



void* groupAdmin(void* groupAdminQueue){
    CQueue* queue = (CQueue*)groupAdminQueue;

    char *msg, *command, *ip, *result, output[1000]="answer$$";

    while(1){

        pthread_mutex_lock(&groupAdminMutex);
        
        if(!cqueue_is_empty(queue)){

            msg  = (char*)cqueue_pop(queue);
            pthread_mutex_unlock(&groupAdminMutex);

            command = getNewToken(&msg);
            ip = getNewToken(&msg);


            if(strcmp(command, "CreateGroup") == 0){
                result = CreateGroup(msg);
            }

            if(strcmp(command, "DeleteGroup") == 0){
                DeleteGroup(msg);
                continue;
            }

            if(strcmp(command, "SearchGroup") == 0){
                result = SearchGroup(msg);
            }

            if(strcmp(command, "JoinGroup") == 0){
                result = JoinGroup(msg);
            }

            if(strcmp(command, "LeaveGroup") == 0){
                LeaveGroup(msg);
                continue;
            }

            if(strcmp(command, "GetGroupMembers") == 0){
                result = GetGroupMembers(msg);
            }

            if(strcmp(command, "GetGroupRequests") == 0){
                result = GetGroupRequests(msg);
            }

            if(strcmp(command, "AcceptGroupRequests") == 0){
                AcceptGroupRequests(msg);
                continue;
            }

            if(strcmp(command, "RejectGroupRequests") == 0){
                RejectGroupRequests(msg);
                continue;
            }

            pthread_mutex_lock(&msgSenderMutex);

            strcat(output,strcat(strcat(ip, "$$"), result));
            cqueue_push(msgSenderQueue, output);

            pthread_mutex_unlock(&msgSenderMutex);
            
        }
        pthread_mutex_unlock(&groupAdminMutex);
    }
}