package com.example.client.View.Activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.graphics.Color;
import android.os.Bundle;

import com.example.client.Controller.BevandaController;
import com.example.client.Controller.OrdineController;
import com.example.client.Controller.UtenteController;
import com.example.client.Model.Bevanda;
import com.example.client.Model.Utente;
import com.example.client.View.Fragment.FragmentHome.CartFragment;
import com.example.client.R;
import com.example.client.View.Fragment.FragmentHome.MenuFragment;
import com.example.client.View.Fragment.FragmentHome.SettingFragment;
import com.google.android.material.tabs.TabLayout;

import java.util.ArrayList;

public class HomeActivity extends AppCompatActivity {

    private TabLayout tabLayout;

    private MenuFragment menuFragment = new MenuFragment();
    private SettingFragment settingFragment = new SettingFragment();
    private CartFragment cartFragment = new CartFragment();

    private String utente;

    private ArrayList<Bevanda> bevande;

    private ArrayList<Bevanda> carrello;

    private UtenteController utenteController = new UtenteController();

    private BevandaController bevandaController = new BevandaController();

    private OrdineController ordineController = new OrdineController();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        utente = getIntent().getStringExtra("utenteUsername");

        new Thread(()->{

            bevande = bevandaController.getBevande(utente);
            carrello = ordineController.getCarrello(utente);

        }).start();




        tabLayout = findViewById(R.id.tabLayoutHome);

        tabLayout.addTab(tabLayout.newTab().setIcon(R.drawable.setting));
        tabLayout.addTab(tabLayout.newTab().setIcon(R.drawable.baseline_menu_book_24));
        tabLayout.addTab(tabLayout.newTab().setIcon(R.drawable.baseline_shopping_cart_24));
        tabLayout.setTabGravity(tabLayout.GRAVITY_FILL);

        tabLayout.setSelectedTabIndicatorColor(Color.parseColor("#FF6E01"));

        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.replace(R.id.constraintHome, menuFragment, null);
        fragmentTransaction.commit();


        tabLayout.setOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                if(tab.getPosition() == 0){
                    tab.getIcon().setTint(Color.parseColor("#FF6E01"));
                    FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                    fragmentTransaction.replace(R.id.constraintHome, settingFragment, null);
                    fragmentTransaction.commit();
                }else if(tab.getPosition() == 1){
                    tab.getIcon().setTint(Color.parseColor("#FF6E01"));
                    FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                    fragmentTransaction.replace(R.id.constraintHome, menuFragment, null);
                    fragmentTransaction.commit();
                }else {
                    tab.getIcon().setTint(Color.parseColor("#FF6E01"));
                    FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                    fragmentTransaction.replace(R.id.constraintHome, cartFragment, null);
                    fragmentTransaction.commit();
                }
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {

            }
        });

    }

    public MenuFragment getMenuFragment() {
        return menuFragment;
    }

    public void setMenuFragment(MenuFragment menuFragment) {
        this.menuFragment = menuFragment;
    }

    public SettingFragment getSettingFragment() {
        return settingFragment;
    }

    public void setSettingFragment(SettingFragment settingFragment) {
        this.settingFragment = settingFragment;
    }

    public CartFragment getCartFragment() {
        return cartFragment;
    }

    public void setCartFragment(CartFragment cartFragment) {
        this.cartFragment = cartFragment;
    }

    public String getUtente() {
        return utente;
    }

    public void setUtente(String utente) {
        this.utente = utente;
    }

    public ArrayList<Bevanda> getBevande() {
        return bevande;
    }

    public void setBevande(ArrayList<Bevanda> bevande) {
        this.bevande = bevande;
    }

    public ArrayList<Bevanda> getCarrello() {
        return carrello;
    }

    public void setCarrello(ArrayList<Bevanda> carrello) {
        this.carrello = carrello;
    }

    public UtenteController getUtenteController() {
        return utenteController;
    }

    public void setUtenteController(UtenteController utenteController) {
        this.utenteController = utenteController;
    }

    public BevandaController getBevandaController() {
        return bevandaController;
    }

    public void setBevandaController(BevandaController bevandaController) {
        this.bevandaController = bevandaController;
    }

    public OrdineController getOrdineController() {
        return ordineController;
    }

    public void setOrdineController(OrdineController ordineController) {
        this.ordineController = ordineController;
    }

    @Override
    public void onBackPressed(){}

}