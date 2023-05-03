#include "userAdmin.h"


char* LogIn(char* msg){

    char* username = getNewToken(&msg);
    char* password = getNewToken(&msg);

    char* s1 = "SELECT * FROM utenti WHERE nome_utente = '";
    char* s2 = "' AND password = '";
    char* s3 = "'";

    char* strings[] = {s1, username, s2, password, s3, NULL};

    PGresult *res = runQuery(strings);

    if(PQntuples(res) == 0)
        return "error$$";
    else
        return strcat(PQgetvalue(res, 0, 1), "$$");
}


char* ForgotPwd(char* msg){
    
    char* username = getNewToken(&msg);
    char* risposta = getNewToken(&msg);

    char* s1 = "SELECT * FROM risposte_sicurezza WHERE id_utente IN (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s2 = "') AND risposta = '";
    char* s3 = "'";

    char* strings[] = {s1, username, s2, risposta, s3, NULL};

    if(PQntuples(runQuery(strings)) == 0)
        return "error$$";
    else
        return "ok$$";
    
}


char* CreateUser(char* msg){
    
    char* username = getNewToken(&msg);
    char* password = getNewToken(&msg);
    char* id_domanda = getNewToken(&msg);
    char* risposta = getNewToken(&msg);

    char* s1 = "INSERT INTO utenti (id_utente, nome_utente, password) VALUES (nextval('id_utente_seq'), '";
    char* s2 = "', '";
    char* s3 = "')";
    
    char *strings[] = {s1, username, s2, password, s3, NULL};

    PGresult *res = runQuery(strings);

    if(PQresultStatus(res) == PGRES_COMMAND_OK){

        s1 = "INSERT INTO  risposte_sicurezza (id_utente, id_domanda, risposta) VALUES ((SELECT id_utente FROM utenti WHERE nome_utente = '";
        s2 = "'), '";
        s3 = "', '";
        char* s4 = "')";

        char *strings2[] = {s1, username, s2, id_domanda, s3, risposta, s4, NULL};

        if(PQresultStatus(runQuery(strings2)) == PGRES_COMMAND_OK)
            return "ok$$";
        else{

            s1 = "DELETE FROM utenti WHERE nome_utente = '";
            s2 = "'";
            char *strings3[] = {s1, username, s2, NULL};

            runQuery(strings3);
            return PQresultErrorMessage(res);
        }    
    }else
        return PQresultErrorMessage(res);
}


char* DeleteUser(char* msg){
    
    char* username = getNewToken(&msg);
    char* password = getNewToken(&msg);

    char* s1 = "DELETE FROM utenti WHERE nome_utente = '";
    char* s2 = "' AND password = '";
    char* s3 = "'";

    char* strings[] = {s1, username, s2, password, s3, NULL};

    PGresult *res = runQuery(strings);

    if(PQresultStatus(res) == PGRES_COMMAND_OK)
        return "ok$$";
    else
        return "error$$";
}


char* ChangePwd(char* msg){
        
    char* username = getNewToken(&msg);
    char* password = getNewToken(&msg);
    char* newpassword = getNewToken(&msg);

    char* s1 = "SELECT * FROM utenti WHERE nome_utente = '";
    char* s2 = "' AND password = '";
    char* s3 = "'";

    char* strings[] = {s1, username, s2, password, s3, NULL};

    if(PQntuples(runQuery(strings)) == 0)
        return "error1$$";

    s1 = "UPDATE utenti SET password = '";
    s2 = "' WHERE nome_utente = '";
    s3 = "' AND password = '";
    char* s4 = "'";

    char* strings2[] = {s1, newpassword, s2, username, s3, password, s4, NULL};

    if(PQresultStatus(runQuery(strings2)) == PGRES_COMMAND_OK)
        return "ok$$";
    else
        return "error2$$";
}


char* GetQuestion(char* msg){
    
    char* username = getNewToken(&msg);
    char* s1 = "SELECT domanda FROM domande_sicurezza WHERE id_domanda = (SELECT id_domanda FROM risposte_sicurezza WHERE id_utente = (SELECT id_utente FROM utenti WHERE nome_utente = '";
    char* s2 = "'))";

    char* strings[] = {s1, username, s2, NULL};

    PGresult *res = runQuery(strings);

    if(PQntuples(res) == 0)
        return "error$$";
    else
        return strcat(PQgetvalue(res, 0, 0), "$$");
}


char* GetAllQuestions(char* msg){
    
    char* s1 = "SELECT * FROM domande_sicurezza";

    char* strings[] = {s1, NULL};

    PGresult *res = runQuery(strings);

    if(PQntuples(res) == 0)
        return "error$$";
    else{
        char* result = (char*)malloc(sizeof(char)*1000);
        for(int i = 0; i < PQntuples(res); i++)
            strcat(strcat(result, PQgetvalue(res, i, 1)), "$$");
        
        return result;
    }
}


void* userAdmin(void* userAdminQueue){

    CQueue* queue = (CQueue*)userAdminQueue;

    char *msg, *command, *ip, *result="", output[1000]="answer$$";

    while(1){

        pthread_mutex_lock(&userAdminMutex);
        
        if(!cqueue_is_empty(queue)){

            msg  = (char*)cqueue_pop(queue);
            pthread_mutex_unlock(&userAdminMutex);

            command = getNewToken(&msg);
            ip = getNewToken(&msg);


            if(strcmp(command, "CreateUser") == 0){
                result =  CreateUser(msg);

                if(strcmp(result, "ok$$") == 0){

                    client newClient;
                    newClient.ip = ip;
                    newClient.username = result;

                    pthread_mutex_lock(&clientsMutex);

                    clients = insert(clients, newClient);

                    pthread_mutex_unlock(&clientsMutex);                    
                }
            }

            if(strcmp(command, "LogIn") == 0){
                result =  LogIn(msg);

                if(strcmp(result, "ok$$") == 0){

                    client newClient;
                    newClient.ip = ip;
                    newClient.username = result;

                    pthread_mutex_lock(&clientsMutex);

                    clients = insert(clients, newClient);

                    pthread_mutex_unlock(&clientsMutex);                    
                    
                }
            }

            if(strcmp(command, "DeleteUser") == 0){
                result = DeleteUser(msg);

                if(strcmp(result, "ok$$") == 0){

                    pthread_mutex_lock(&clientsMutex);

                    clients = deleteData(clients, ip);

                    pthread_mutex_unlock(&clientsMutex);
                }
            }

            if(strcmp(command, "ChangePwd") == 0){
                result = ChangePwd(msg);
            }

            if(strcmp(command, "ForgotPwd") == 0){
                printf("Forgotpwd\n");
                result = ForgotPwd(msg);
            }

            if(strcmp(command, "GetQuestion") == 0){
                result = GetQuestion(msg);
            }

            if(strcmp(command, "GetAllQuestions") == 0){
                result = GetAllQuestions(msg);
            }
      
      
            pthread_mutex_lock(&msgSenderMutex);

            strcat(output,strcat(strcat(ip, "$$"), result));
            cqueue_push(msgSenderQueue, output);

            pthread_mutex_unlock(&msgSenderMutex);
            
        }
        
        pthread_mutex_unlock(&userAdminMutex);
    }
}