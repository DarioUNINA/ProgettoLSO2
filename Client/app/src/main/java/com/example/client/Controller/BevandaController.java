package com.example.client.Controller;

import com.google.gson.Gson;
import com.example.client.Model.Bevanda;
import com.example.client.Model.Utente;


import org.modelmapper.ModelMapper;

import java.util.ArrayList;
import java.util.List;

public class BevandaController {

    private ConnessioneController connessioneController;
    private ModelMapper modelMapper;
    private Gson gson;

    public BevandaController() {
        connessioneController = new ConnessioneController();
        modelMapper = new ModelMapper();
        gson = new Gson();
    }


    public ArrayList<Bevanda> getBevande(String utente){
        ArrayList<Bevanda> bevande = new ArrayList<>();
        String result = new String();

        connessioneController.startConnection();

        connessioneController.writeOnOutput("bevanda$$getBevande$$"+utente+ "$$");

        result = connessioneController.readFromInput();
                connessioneController.closeConnection();


        if(result != null){
            result = result.replaceAll("\\}\\s*\\{", "},{");

            result = "[" + result + "]";

            Bevanda[] bevandeArray = gson.fromJson(result, Bevanda[].class);

            for (Bevanda bevanda : bevandeArray)
                bevande.add(bevanda);
        }


        return bevande;
    }

    public String bevandaToJson(Bevanda bevanda){
        String json = gson.toJson(bevanda);
        return json;
    }

    public Bevanda jsonToBevanda(String json){
        Bevanda bevanda = gson.fromJson(json, Bevanda.class);
        return bevanda;
    }

    public String utenteToJson(Utente utente){
        String json = gson.toJson(utente);
        return json;
    }

}