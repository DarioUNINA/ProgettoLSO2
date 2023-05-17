package com.example.client.Controller;

import com.example.client.Model.Bevanda;
import com.example.client.Model.Utente;
import com.google.gson.Gson;

import org.modelmapper.ModelMapper;

import java.util.ArrayList;

public class OrdineController {

    private ConnessioneController connessioneController;
    private ModelMapper modelMapper;
    private Gson gson;

    public OrdineController(){
        connessioneController = new ConnessioneController();
        modelMapper = new ModelMapper();
        gson = new Gson();
    }

    public void chiudiCarrello(String utente){
        connessioneController.startConnection();
        connessioneController.writeOnOutput("ordine$$chiudiOrdine$$"+utente+"$$");
        connessioneController.closeConnection();
    }


    public ArrayList<Bevanda> getCarrello(String utente){
        ArrayList<Bevanda> bevande = new ArrayList<>();
        String result = new String();

        connessioneController.startConnection();

        connessioneController.writeOnOutput("ordine$$getCarrello$$"+utente+ "$$");

        result = connessioneController.readFromInput();

                connessioneController.closeConnection();


        // Separo i JSON e creo un array che riverso nell'arraylist
        if(result != null){
            result = result.replaceAll("\\}\\s*\\{", "},{");

            result = "[" + result + "]";

            Bevanda[] bevandeArray = gson.fromJson(result, Bevanda[].class);

            // Fai qualcosa con l'array di oggetti Bevanda
            for (Bevanda bevanda : bevandeArray)
                bevande.add(bevanda);
        }


        return bevande;
    }


    public void aggiungiACarrello(String utente, String bevanda){

        connessioneController.startConnection();

        connessioneController.writeOnOutput("ordine$$addBevandaToOrdine$$"+bevanda+"$$"+utente+ "$$");

        connessioneController.closeConnection();

    }


    public void rimuoviDaCarrello(String utente, String bevanda){

        connessioneController.startConnection();

        connessioneController.writeOnOutput("ordine$$removeBevandaFromOrdine$$"+bevanda+"$$"+utente+ "$$");

        connessioneController.closeConnection();

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
