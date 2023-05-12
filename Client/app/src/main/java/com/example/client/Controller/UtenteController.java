package com.example.client.Controller;


import com.google.gson.Gson;
import com.example.client.Model.Utente;


import org.modelmapper.ModelMapper;
import org.modelmapper.TypeToken;

import java.io.IOException;

public class UtenteController {

    private ConnessioneController connessioneController;
    private ModelMapper modelMapper;
    private Gson gson;

    public UtenteController(){
        connessioneController = new ConnessioneController();
        modelMapper = new ModelMapper();
        gson = new Gson();
    }


    public Utente getUtente(String username, String password){


        Utente utente = null;
        String result = null;

        connessioneController.startConnection();


        //richiesta
        connessioneController.writeOnOutput("getUtente$$"+username+"$$"+password);


        //ricezione
        result = connessioneController.readFromInput();

        System.out.println(result);


        // conversione da json ad oggetto
        utente = jsonToUtente(result);


        connessioneController.closeConnection();


        return utente;
    }

    public void registraUtente(Utente utente){

        connessioneController.startConnection();

        //richiesta
        connessioneController.writeOnOutput("registraUtente$$"+utenteToJson(utente));

        connessioneController.closeConnection();

    }


    public String utenteToJson(Utente utente){
        String json = gson.toJson(utente);
        return json;
    }

    public Utente jsonToUtente(String json){
        Utente utente = gson.fromJson(json, Utente.class);
        return utente;
    }

}
