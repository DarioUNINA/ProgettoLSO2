package com.example.client.Model;


public class Bevanda {

    private String nome;

    private String descrizione;
    private Float prezzo;
    private String tipo;

    public Bevanda(){

    }

    public Bevanda(String nome, Float prezzo) {
        this.nome = nome;
        this.prezzo = prezzo;
    }

    public Bevanda(Integer id, String nome,String descrizione, Float prezzo, String tipo) {
        this.nome = nome;
        this.descrizione = descrizione;
        this.prezzo = prezzo;
        this.tipo = tipo;
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

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }


}