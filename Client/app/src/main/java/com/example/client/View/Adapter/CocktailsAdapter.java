package com.example.client.View.Adapter;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
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
import com.example.client.View.Fragment.FragmentHome.MenuFragment;
import com.google.android.material.card.MaterialCardView;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class CocktailsAdapter extends RecyclerView.Adapter<CocktailsAdapter.CocktailsHolder> {

    private Context context;
    private CocktailsAdapter.OnCocktailsClickListner onCocktailsClickListner;

    public ArrayList<Bevanda> cocktails = new ArrayList<>();

    private MenuFragment menuFragment;


    public CocktailsAdapter(ArrayList<Bevanda> bevande, Context context, MenuFragment menuFragment){
        this.menuFragment = menuFragment;
        this.context = menuFragment.getContext();
        for(Bevanda b: bevande)
            if(b.getCategoria().equals("cocktail"))
                cocktails.add(b);

    }



    public interface OnCocktailsClickListner{
        void onCategoriaClicked(int position);
    }


    @NonNull
    @Override
    public CocktailsAdapter.CocktailsHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_bevanda, parent, false);


        return new CocktailsAdapter.CocktailsHolder(v);
    }


    @Override
    public void onBindViewHolder(@NonNull CocktailsAdapter.CocktailsHolder holder, int position) {
        holder.txtNome.setText(cocktails.get(position).getNome());
        holder.txtPrezzo.setText(String.valueOf(cocktails.get(position).getPrezzo()));
        holder.descrizione = cocktails.get(position).getDescrizione();
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
                        .setTitle("Aggiungi a Carrello")
                        .setMessage("Sei sicuro di voler aggiungere " + cocktails.get(position).getNome() + " al carrello?")
                        .setNegativeButton(android.R.string.no, null)
                        .setPositiveButton(android.R.string.yes,  new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                new Thread(()->{
                                    OrdineController controller = new OrdineController();
                                    controller.aggiungiACarrello(((HomeActivity)menuFragment.getActivity()).getUtente(), cocktails.get(position).getNome());
                                    ((HomeActivity)menuFragment.getActivity()).getCarrello().add(cocktails.get(position));

                                }).start();
                            }
                        })
                        .create().show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return cocktails.size();
    }

    public class CocktailsHolder extends RecyclerView.ViewHolder{

        private TextView txtNome, txtPrezzo;
        private ImageView smoothieView; //lo setta invisible
        private FloatingActionButton infoButton;

        private MaterialCardView cardView;

        private String descrizione;

        public CocktailsHolder(@NonNull View itemView) {
            super(itemView);

            txtNome = itemView.findViewById(R.id.txtNome);
            txtPrezzo = itemView.findViewById(R.id.txtPrezzo);
            smoothieView = itemView.findViewById(R.id.smoothieImageView);
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

    public OnCocktailsClickListner getOnCocktailsClickListner() {
        return onCocktailsClickListner;
    }

    public void setOnCocktailsClickListner(OnCocktailsClickListner onCocktailsClickListner) {
        this.onCocktailsClickListner = onCocktailsClickListner;
    }
}
