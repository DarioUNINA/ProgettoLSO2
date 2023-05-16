package com.example.client.View.Fragment.FragmentHome;

import android.graphics.Color;
import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.client.R;
import com.example.client.View.Activity.HomeActivity;
import com.example.client.View.Adapter.CocktailsAdapter;
import com.example.client.View.Adapter.SmoothieAdapter;
import com.google.android.material.tabs.TabLayout;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link MenuFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class MenuFragment extends Fragment {

    private TabLayout tabLayout;
    private RecyclerView recyclerViewBevande;


    private CocktailsAdapter cocktailsAdapter;

    private CocktailsAdapter.OnCocktailsClickListner onCategoriaClickListner;

    private SmoothieAdapter smoothieAdapter;

    private SmoothieAdapter.OnSmoothieClickListner onSmoothieClickListner;


    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public MenuFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment MenuFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static MenuFragment newInstance(String param1, String param2) {
        MenuFragment fragment = new MenuFragment();
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
        View rootView =  inflater.inflate(R.layout.fragment_menu, container, false);

        tabLayout = rootView.findViewById(R.id.tabLayoutMenu);
        recyclerViewBevande = rootView.findViewById(R.id.recyclerViewBevande);

        tabLayout.addTab(tabLayout.newTab().setText("Cocktails"));
        tabLayout.addTab(tabLayout.newTab().setText("Smoothie"));
        tabLayout.setTabGravity(tabLayout.GRAVITY_FILL);
        tabLayout.setSelectedTabIndicatorColor(Color.parseColor("#FF6E01"));


        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(getContext());
        linearLayoutManager.setOrientation(LinearLayoutManager.VERTICAL);
        recyclerViewBevande.setLayoutManager(linearLayoutManager);

        cocktailsAdapter = new CocktailsAdapter(((HomeActivity)getActivity()).getBevande(), recyclerViewBevande.getContext());
        recyclerViewBevande.setAdapter(cocktailsAdapter);
        cocktailsAdapter.notifyDataSetChanged();

        smoothieAdapter = new SmoothieAdapter(((HomeActivity)getActivity()).getBevande(), recyclerViewBevande.getContext());


        tabLayout.setOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                if(tab.getPosition() == 0){
                    recyclerViewBevande.setLayoutManager(linearLayoutManager);
                    recyclerViewBevande.setAdapter(cocktailsAdapter);
                    cocktailsAdapter.notifyDataSetChanged();
                }else {
                    recyclerViewBevande.setLayoutManager(linearLayoutManager);
                    recyclerViewBevande.setAdapter(smoothieAdapter);
                    smoothieAdapter.notifyDataSetChanged();
                }
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {

            }
        });

        return rootView;
    }


    public CocktailsAdapter getCocktailsAdapter() {
        return cocktailsAdapter;
    }

    public void setCocktailsAdapter(CocktailsAdapter cocktailsAdapter) {
        this.cocktailsAdapter = cocktailsAdapter;
    }

    public SmoothieAdapter getSmoothieAdapter() {
        return smoothieAdapter;
    }

    public void setSmoothieAdapter(SmoothieAdapter smoothieAdapter) {
        this.smoothieAdapter = smoothieAdapter;
    }
}