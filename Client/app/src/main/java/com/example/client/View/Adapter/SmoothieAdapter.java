package com.example.client.View.Adapter;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.view.menu.MenuAdapter;
import androidx.recyclerview.widget.RecyclerView;

import com.example.client.Controller.OrdineController;
import com.example.client.Model.Bevanda;
import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.example.client.View.Fragment.FragmentHome.MenuFragment;
import com.google.android.material.card.MaterialCardView;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class SmoothieAdapter extends RecyclerView.Adapter<SmoothieAdapter.SmoothieHolder> {

    private Context context;
    private SmoothieAdapter.OnSmoothieClickListner onSmoothieClickListner;
    public ArrayList<Bevanda> smoothies = new ArrayList<>();
    private MenuFragment menuFragment;

    public SmoothieAdapter(ArrayList<Bevanda> bevande, Context context, MenuFragment menuFragment){
        this.menuFragment = menuFragment;
        this.context = context;
        for(Bevanda b: bevande)
            if(b.getCategoria().equals("smoothie"))
                smoothies.add(b);
    }

    public interface OnSmoothieClickListner{
        void onSmoothieClicked(int position);
    }



    @NonNull
    @Override
    public SmoothieAdapter.SmoothieHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_bevanda, parent, false);


        return new SmoothieAdapter.SmoothieHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull SmoothieAdapter.SmoothieHolder holder, int position) {
        holder.txtNome.setText(smoothies.get(position).getNome());
        holder.txtPrezzo.setText(String.valueOf(smoothies.get(position).getPrezzo()));
        holder.descrizione = smoothies.get(position).getDescrizione();
        holder.cocktailView.setVisibility(View.INVISIBLE);

        holder.infoButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new AlertDialog.Builder(context)
                        .setTitle(smoothies.get(position).getNome())
                        .setMessage(holder.descrizione)
                        .create().show();
            }
        });
        holder.cardView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new AlertDialog.Builder(context)
                        .setTitle("Aggiungi a Carrello")
                        .setMessage("Sei sicuro di voler aggiungere " + smoothies.get(position).getNome() + " al carrello?")
                        .setNegativeButton(android.R.string.no, null)
                        .setPositiveButton(android.R.string.yes,  new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialogInterface, int i) {
                                new Thread(()->{
                                    OrdineController controller = new OrdineController();
                                    String output = controller.aggiungiACarrello(((HomeActivity)menuFragment.getActivity()).getUtente(), smoothies.get(position).getNome());
                                    if(output == null) {
                                        menuFragment.getActivity().runOnUiThread(() -> {
                                            new AlertDialog.Builder(menuFragment.getActivity())
                                                    .setTitle("ERRORE")
                                                    .setMessage("Errore di connessione, riprova")
                                                    .create().show();
                                        });
                                    }

                                }).start();
                                ((HomeActivity)menuFragment.getActivity()).getCarrello().add(smoothies.get(position));
                            }
                        })
                        .create().show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return smoothies.size();
    }

    public class SmoothieHolder extends RecyclerView.ViewHolder{


        private TextView txtNome, txtPrezzo;
        private ImageView cocktailView; //lo setta invisible
        private FloatingActionButton infoButton;
        private MaterialCardView cardView;

        private String descrizione;

        public SmoothieHolder(@NonNull View itemView) {
            super(itemView);

            txtNome = itemView.findViewById(R.id.txtNome);
            txtPrezzo = itemView.findViewById(R.id.txtPrezzo);
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
