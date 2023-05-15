package com.example.client.View.Activity;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.graphics.Color;
import android.os.Bundle;

import com.example.client.Controller.BevandaController;
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

    private UtenteController utenteController = new UtenteController();

    private BevandaController bevandaController = new BevandaController();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        utente = getIntent().getStringExtra("utenteUsername");
        bevande = bevandaController.getBevande(utente);


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



//        FragmentManager fragmentManager = getSupportFragmentManager();
//        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
//        fragmentTransaction.replace(R.id.constraintHome, , null);
//        fragmentTransaction.commit();

    }
}