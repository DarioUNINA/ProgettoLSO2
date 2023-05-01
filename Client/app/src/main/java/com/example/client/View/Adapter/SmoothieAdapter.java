package com.example.client.View.Adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.client.R;

public class SmoothieAdapter extends RecyclerView.Adapter<SmoothieAdapter.SmoothieHolder> {

    private Context context;
    private SmoothieAdapter.OnSmoothieClickListner onSmoothieClickListner;


    public interface OnSmoothieClickListner{
        void onSmoothieClicked(int position);
    }



    @NonNull
    @Override
    public SmoothieAdapter.SmoothieHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.fragment_cocktails, parent, false);


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
