package com.example.client.View.Adapter;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Looper;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.client.Controller.OrdineController;
import com.example.client.Model.Bevanda;
import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.example.client.View.Activity.LoginActivity;
import com.example.client.View.Fragment.FragmentHome.CartFragment;
import com.google.android.material.card.MaterialCardView;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class CarrelloAdapter extends RecyclerView.Adapter<CarrelloAdapter.CarrelloHolder> {

    private Context context;
    private CocktailsAdapter.OnCocktailsClickListner onCocktailsClickListner;

    private ArrayList<Bevanda> bevande = new ArrayList<>();

    private CartFragment cartFragment;


    public CarrelloAdapter(ArrayList<Bevanda> bevande, Context context, CartFragment cartFragment){
        this.cartFragment = cartFragment;
        this.context = context;
        this.bevande = bevande;
    }





    @NonNull
    @Override
    public CarrelloAdapter.CarrelloHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_bevanda, parent, false);

        return new CarrelloAdapter.CarrelloHolder(v);
    }


    @Override
    public void onBindViewHolder(@NonNull CarrelloAdapter.CarrelloHolder holder, int position) {
        holder.txtNome.setText(bevande.get(position).getNome());
        holder.txtPrezzo.setText(String.valueOf(bevande.get(position).getPrezzo()));
        holder.descrizione = bevande.get(position).getDescrizione();

        if(bevande.get(position).getCategoria().equals("smoothie"))
            holder.cocktailView.setVisibility(View.INVISIBLE);
        else
            holder.smoothieView.setVisibility(View.INVISIBLE);

        holder.infoButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new AlertDialog.Builder(context)
                        .setTitle("Descrizione")
                        .setMessage(holder.descrizione)
                        .create().show();
            }
        });

        holder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                    new AlertDialog.Builder(context)
                        .setTitle("Rimozione Bevanda")
                        .setMessage("Sei sicuro di voler rimuovere la bevanda dal carrello?")
                        .setNegativeButton(android.R.string.no, null)
                        .setPositiveButton(android.R.string.yes,  new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {

                                new Thread(()->{
                                    OrdineController ordineController = new OrdineController();
                                    ordineController.rimuoviDaCarrello(((HomeActivity)cartFragment.getActivity()).getUtente(), holder.txtNome.getText().toString());

                                }).start();


                                    for(int j = 0; j< bevande.size(); j++)
                                        if(bevande.get(j).getNome().equals(holder.txtNome.getText())) {
                                            bevande.remove(j);
                                            break;
                                        }

                                cartFragment.updateTotale();
                                notifyDataSetChanged();
                            }
                        }).create().show();


            }
        });
    }

    @Override
    public int getItemCount() {
        return bevande.size();
    }

    public class CarrelloHolder extends RecyclerView.ViewHolder{

        private TextView txtNome, txtPrezzo;
        private ImageView smoothieView, cocktailView;
        private FloatingActionButton infoButton;

        private MaterialCardView cardView;

        private String descrizione;

        public CarrelloHolder(@NonNull View itemView) {
            super(itemView);

            txtNome = itemView.findViewById(R.id.txtNome);
            txtPrezzo = itemView.findViewById(R.id.txtPrezzo);
            smoothieView = itemView.findViewById(R.id.smoothieImageView);
            cocktailView = itemView.findViewById(R.id.cockatailImageView);
            infoButton = itemView.findViewById(R.id.btnInfo);
            cardView = itemView.findViewById(R.id.bevandaCardView);

        }
    }


    public Context getContext() {
        return context;
    }

    public void setContext(Context context) {
        this.context = context;
    }



}
