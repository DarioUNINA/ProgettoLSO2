package com.example.client.View.Adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.client.Model.Bevanda;
import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class CocktailsAdapter extends RecyclerView.Adapter<CocktailsAdapter.CocktailsHolder> {

    private Context context;
    private CocktailsAdapter.OnCocktailsClickListner onCocktailsClickListner;

    private ArrayList<Bevanda> cocktails = new ArrayList<>();


    public CocktailsAdapter(ArrayList<Bevanda> bevande, Context context){
//        this.context = context;
//        for(Bevanda b: bevande)
//            if(b.getCategoria().equals("cocktail"))
//                cocktails.add(b);
        cocktails.add(new Bevanda("noome", "descrizione", "categoria", 0.0f ));

    }



    public interface OnCocktailsClickListner{
        void onCategoriaClicked(int position);
    }


    @NonNull
    @Override
    public CocktailsAdapter.CocktailsHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_cocktails, parent, false);



        return new CocktailsAdapter.CocktailsHolder(v);
    }


    @Override
    public void onBindViewHolder(@NonNull CocktailsAdapter.CocktailsHolder holder, int position) {
        holder.txtNome.setText(cocktails.get(position).getNome());
        holder.txtPrezzo.setText(String.valueOf(cocktails.get(position).getPrezzo()));
        holder.descrizione = cocktails.get(position).getDescrizione();
        holder.smoothieView.setVisibility(View.INVISIBLE);
        System.out.println("FATTO\n\n\n\n");
    }

    @Override
    public int getItemCount() {
        return 0;
    }

    public class CocktailsHolder extends RecyclerView.ViewHolder{

        private TextView txtNome, txtPrezzo;
        private ImageView smoothieView; //lo setta invisible
        private FloatingActionButton infoButton;

        private String descrizione;

        public CocktailsHolder(@NonNull View itemView) {
            super(itemView);

            txtNome = itemView.findViewById(R.id.txtNome);
            txtPrezzo = itemView.findViewById(R.id.txtPrezzo);
            smoothieView = itemView.findViewById(R.id.smoothieImageView);
            infoButton = itemView.findViewById(R.id.btnInfo);


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
