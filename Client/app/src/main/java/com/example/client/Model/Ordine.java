package com.example.client.Model;

import java.util.List;

public class Ordine {

    private int idOrdine;

    private boolean chiuso;

    private List<Bevanda> bevandaList;

    public Ordine() {
    }


    public Ordine(int idOrdine, boolean chiuso, List<Bevanda> bevandaList) {
        this.idOrdine = idOrdine;
        this.chiuso = chiuso;
        this.bevandaList = bevandaList;
    }

    public int getIdOrdine() {
        return idOrdine;
    }

    public void setIdOrdine(int idOrdine) {
        this.idOrdine = idOrdine;
    }

    public boolean isChiuso() {
        return chiuso;
    }

    public void setChiuso(boolean chiuso) {
        this.chiuso = chiuso;
    }

    public List<Bevanda> getBevandaList() {
        return bevandaList;
    }

    public void setBevandaList(List<Bevanda> bevandaList) {
        this.bevandaList = bevandaList;
    }
}
