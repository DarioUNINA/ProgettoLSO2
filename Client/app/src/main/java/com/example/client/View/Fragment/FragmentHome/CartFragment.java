package com.example.client.View.Fragment.FragmentHome;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;

import androidx.appcompat.widget.AppCompatButton;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.example.client.Controller.OrdineController;
import com.example.client.Model.Bevanda;
import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.example.client.View.Activity.LoginActivity;
import com.example.client.View.Adapter.CarrelloAdapter;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link CartFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class CartFragment extends Fragment {


    private TextView totale;
    private FloatingActionButton conferma;

    private RecyclerView recyclerView;
    private CarrelloAdapter carrelloAdapter;


    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public CartFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment CartFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static CartFragment newInstance(String param1, String param2) {
        CartFragment fragment = new CartFragment();
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


        View rootView = inflater.inflate(R.layout.fragment_cart, container, false);

        recyclerView = rootView.findViewById(R.id.recyclerViewCart);

        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getContext());
        linearLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        recyclerView.setLayoutManager(linearLayoutManager);

        carrelloAdapter = new CarrelloAdapter(((HomeActivity)getActivity()).getCarrello(), getContext(), this);
        recyclerView.setAdapter(carrelloAdapter);
        carrelloAdapter.notifyDataSetChanged();

        totale = rootView.findViewById(R.id.prezzoTxt);
        conferma = rootView.findViewById(R.id.btnPagamento);

        conferma.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new AlertDialog.Builder(getActivity())
                        .setTitle("CONFERMA")
                        .setMessage("Sei sicuro di voler pagare?")
                        .setNegativeButton(android.R.string.no, null)
                        .setPositiveButton(android.R.string.yes,  new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                new Thread(()->{
                                    OrdineController ordineController = new OrdineController();
                                    ordineController.chiudiCarrello(((HomeActivity)getActivity()).getUtente());
                                }).start();
                                ((HomeActivity)getActivity()).getCarrello().clear();
                                carrelloAdapter.notifyDataSetChanged();
                                updateTotale();

                            }
                        }).create().show();
            }
        });

        updateTotale();

        return rootView;
    }

    public TextView getTotale() {
        return totale;
    }

    public void setTotale(TextView totale) {
        this.totale = totale;
    }

    public void updateTotale(){
        float tot = 0;
        for(Bevanda b: ((HomeActivity)getActivity()).getCarrello())
            tot+=b.getPrezzo();

        totale.setText("$"+String.valueOf(tot));
    }
}