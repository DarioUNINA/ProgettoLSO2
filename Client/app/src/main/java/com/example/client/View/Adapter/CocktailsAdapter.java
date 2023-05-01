package com.example.client.View.Adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.client.R;

public class CocktailsAdapter extends RecyclerView.Adapter<CocktailsAdapter.CocktailsHolder> {

    private Context context;
    private CocktailsAdapter.OnCocktailsClickListner onCocktailsClickListner;


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

    }

    @Override
    public int getItemCount() {
        return 0;
    }

    public class CocktailsHolder extends RecyclerView.ViewHolder{


        public CocktailsHolder(@NonNull View itemView) {
            super(itemView);

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
