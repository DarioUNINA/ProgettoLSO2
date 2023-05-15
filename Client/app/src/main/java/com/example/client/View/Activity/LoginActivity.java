package com.example.client.View.Activity;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;

import com.example.client.View.Fragment.FragmentLogIn.LogInFragment;
import com.example.client.R;
import com.example.client.View.Fragment.FragmentLogIn.SignUpFragment;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.tabs.TabLayout;

public class LoginActivity extends AppCompatActivity {

    private TabLayout tabLayout;
    private FloatingActionButton btnExit;
    private float v = 0;

    LogInFragment logInFragment = new LogInFragment();

    SignUpFragment signUpFragment = new SignUpFragment();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.acitivty_login);


        tabLayout = findViewById(R.id.tabLayout);
        btnExit = findViewById(R.id.btnExit);

        tabLayout.addTab(tabLayout.newTab().setText("LogIn"));
        tabLayout.addTab(tabLayout.newTab().setText("SignUp"));
        tabLayout.setTabGravity(tabLayout.GRAVITY_FILL);

        tabLayout.setSelectedTabIndicatorColor(Color.parseColor("#FF6E01"));



        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.replace(R.id.constraintLog, logInFragment, null);
        fragmentTransaction.commit();

        btnExit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new AlertDialog.Builder(LoginActivity.this)
                        .setTitle("Exit")
                        .setMessage("Sei sicuro di voler uscrire dall'applicazione?")
                        .setNegativeButton(android.R.string.no, null)
                        .setPositiveButton(android.R.string.yes, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                finishAffinity();
                                System.exit(0);
                            }
                        }).create().show();
            }
        });


        tabLayout.setOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                if(tab.getPosition() == 0){
                    FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                    fragmentTransaction.replace(R.id.constraintLog, logInFragment, null);
                    fragmentTransaction.commit();
                }else{
                    FragmentTransaction fragmentTransaction = getSupportFragmentManager().beginTransaction();
                    fragmentTransaction.replace(R.id.constraintLog, signUpFragment, null);
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

        btnExit.setTranslationY(300);
        tabLayout.setTranslationY(300);

        btnExit.setAlpha(v);
        tabLayout.setAlpha(v);

        btnExit.animate().translationY(0).alpha(1).setDuration(1000).setStartDelay(400).start();
        tabLayout.animate().translationY(0).alpha(1).setDuration(1000).setStartDelay(100).start();

    }

    public TabLayout getTabLayout() {
        return tabLayout;
    }

    public void setTabLayout(TabLayout tabLayout) {
        this.tabLayout = tabLayout;
    }

    public FloatingActionButton getBtnExit() {
        return btnExit;
    }

    public void setBtnExit(FloatingActionButton btnExit) {
        this.btnExit = btnExit;
    }

    public float getV() {
        return v;
    }

    public void setV(float v) {
        this.v = v;
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        //This is used to hide/show 'Status Bar' & 'System Bar'. Swip bar to get it as visible.
        View decorView = getWindow().getDecorView();
        if (hasFocus) {
            decorView.setSystemUiVisibility(
                    View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                            | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                            | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                            | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                            | View.SYSTEM_UI_FLAG_FULLSCREEN
                            | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
        }
    }

    @Override
    public void onBackPressed(){
        btnExit.callOnClick();
    }
}