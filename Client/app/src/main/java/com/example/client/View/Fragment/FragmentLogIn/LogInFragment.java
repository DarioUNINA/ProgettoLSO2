package com.example.client.View.Fragment.FragmentLogIn;

import static java.lang.Thread.sleep;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.widget.AppCompatButton;
import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.Toast;

import com.example.client.Controller.UtenteController;
import com.example.client.Model.Utente;
import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.example.client.View.Activity.LoginActivity;
import com.google.android.material.card.MaterialCardView;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link LogInFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class LogInFragment extends Fragment {

    private MaterialCardView materialBtnLog, materialUser, materialPwd;
    private EditText edtUsername, edtPassword;

    private UtenteController utenteController = new UtenteController();

    private AppCompatButton btnLogIn;

    float v=0;

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public LogInFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment LogInFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static LogInFragment newInstance(String param1, String param2) {
        LogInFragment fragment = new LogInFragment();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View rootView =  inflater.inflate(R.layout.fragment_log_in, container, false);



        materialBtnLog = rootView.findViewById(R.id.materialBtnLog);
        materialPwd = rootView.findViewById(R.id.materialPwd);
        materialUser = rootView.findViewById(R.id.materialUser);
        edtUsername = rootView.findViewById(R.id.edtUsernameLogIn);
        edtPassword = rootView.findViewById(R.id.edtPasswordLogIn);
        btnLogIn = rootView.findViewById(R.id.btnLogIn);

        btnLogIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                new Thread(()->{
                    String username = edtUsername.getText().toString();
                    String password = edtPassword.getText().toString();
                    Utente utente = null;

//                    if(!(username.isEmpty()) && !(password.isEmpty()))
//                        utente = utenteController.getUtente(username, password);
                    utente = new Utente("Dario", "123");

                    if(utente != null){
                        Intent intent = new Intent(getContext(), HomeActivity.class);
                        intent.putExtra("utenteUsername", utente.getUsername());
                        startActivity(intent);
                    } else {
                        System.out.println("log in fallito");
                    }
                }).start();

            }
        });




        materialUser.setTranslationX(800);
        materialPwd.setTranslationX(800);
        materialBtnLog.setTranslationX(800);


        materialUser.setAlpha(v);
        materialPwd.setAlpha(v);
        materialBtnLog.setAlpha(v);


        materialUser.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(350).start();
        materialPwd.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(450).start();
        materialBtnLog.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(500).start();

        return rootView;
    }

}