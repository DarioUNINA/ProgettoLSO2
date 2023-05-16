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
import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;

public class SmoothieAdapter extends RecyclerView.Adapter<SmoothieAdapter.SmoothieHolder> {

    private Context context;
    private SmoothieAdapter.OnSmoothieClickListner onSmoothieClickListner;
    private ArrayList<Bevanda> smoothies = new ArrayList<>();


    public SmoothieAdapter(ArrayList<Bevanda> bevande, Context context){
        this.context = context;
//        for(Bevanda b: bevande)
//            if(b.getCategoria().equals("smoothie"))
//                smoothies.add(b);
    }

    public interface OnSmoothieClickListner{
        void onSmoothieClicked(int position);
    }



    @NonNull
    @Override
    public SmoothieAdapter.SmoothieHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_smoothie, parent, false);


        return new SmoothieAdapter.SmoothieHolder(v);
    }

    @Override
    public void onBindViewHolder(@NonNull SmoothieAdapter.SmoothieHolder holder, int position) {

    }

    @Override
    public int getItemCount() {
        return 0;
    }

    public class SmoothieHolder extends RecyclerView.ViewHolder{


        private TextView txtNome, txtPrezzo;
        private ImageView cocktailView; //lo setta invisible
        private FloatingActionButton infoButton;

        public SmoothieHolder(@NonNull View itemView) {
            super(itemView);

        }
    }

    public Context getContext() {
        return context;
    }

    public void setContext(Context context) {
        this.context = context;
    }
}
