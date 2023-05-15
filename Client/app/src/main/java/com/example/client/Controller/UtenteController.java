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


        String result = null;

//        connessioneController.startConnection();
//
//
//        //richiesta
//        connessioneController.writeOnOutput( "getUtente$$"+username+"$$"+password);
//
//
//        //ricezione
//        result = connessioneController.readFromInput();
//
//        System.out.println(result);
//
//        connessioneController.closeConnection();

        result = "true";


        if(result.equals("true"))
            return new Utente(username, password);
        else
            return null;

    }

    public Utente registraUtente(String username, String password){

        String result = null;

        connessioneController.startConnection();


        //richiesta
        connessioneController.writeOnOutput( "registrazione$$"+username+"$$"+password);


        //ricezione
        result = connessioneController.readFromInput();

        System.out.println(result);

        connessioneController.closeConnection();

        if(result.equals("true"))
            return new Utente(username, password);
        else
            return null;

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
