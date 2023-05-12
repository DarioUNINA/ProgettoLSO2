package com.example.client.Model;

import java.util.List;

public class Ordine {

    private int idOrdine;
    private String utente;

    private List<Bevanda> bevandaList;
    private boolean chiuso;


    public Ordine() {
    }


    public Ordine(int idOrdine, String utente,List<Bevanda> bevandaList, boolean chiuso) {
        this.idOrdine = idOrdine;
        this.utente = utente;
        this.bevandaList = bevandaList;
        this.chiuso = chiuso;
    }

    public int getIdOrdine() {
        return idOrdine;
    }

    public void setIdOrdine(int idOrdine) {
        this.idOrdine = idOrdine;
    }

    public String getUtente() {
        return utente;
    }

    public void setUtente(String utente) {
        this.utente = utente;
    }

    public List<Bevanda> getBevandaList() {
        return bevandaList;
    }

    public void setBevandaList(List<Bevanda> bevandaList) {
        this.bevandaList = bevandaList;
    }

    public boolean isChiuso() {
        return chiuso;
    }

    public void setChiuso(boolean chiuso) {
        this.chiuso = chiuso;
    }

}
