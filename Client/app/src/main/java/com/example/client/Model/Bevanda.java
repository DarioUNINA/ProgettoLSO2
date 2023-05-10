package com.example.client.Model;

import com.example.client.Model.Enum.TipoBevanda;

public class Bevanda {

    private Integer id;
    private String nome;
    private Float prezzo;
    private TipoBevanda tipo;

    public Bevanda(){

    }

    public Bevanda(String nome, Float prezzo) {
        this.nome = nome;
        this.prezzo = prezzo;
    }

    public Bevanda(Integer id, String nome, Float prezzo, TipoBevanda tipo) {
        this.id = id;
        this.nome = nome;
        this.prezzo = prezzo;
        this.tipo = tipo;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Float getPrezzo() {
        return prezzo;
    }

    public void setPrezzo(Float prezzo) {
        this.prezzo = prezzo;
    }

    public TipoBevanda getTipo() {
        return tipo;
    }

    public void setTipo(TipoBevanda tipo) {
        this.tipo = tipo;
    }


}