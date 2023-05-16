package com.example.client.Model;


public class Bevanda {

    private String nome;

    private String descrizione;
    private Float prezzo;
    private String categoria;

    public Bevanda(){

    }

    public Bevanda(String nome, String descrizione, String categoria, Float prezzo) {
        this.nome = nome;
        this.prezzo = prezzo;
        this.categoria = categoria;
        this.descrizione = descrizione;
    }


    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public Float getPrezzo() {
        return prezzo;
    }

    public void setPrezzo(Float prezzo) {
        this.prezzo = prezzo;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }


}