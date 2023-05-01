package com.example.client.View.Fragment.FragmentLogSign;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.client.R;
import com.google.android.material.card.MaterialCardView;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link SignUpFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class SignUpFragment extends Fragment {

    private MaterialCardView materialBtnSign, materialUser, materialPwd;

    float v=0;

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public SignUpFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment SignUpFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static SignUpFragment newInstance(String param1, String param2) {
        SignUpFragment fragment = new SignUpFragment();
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
        View rootView = inflater.inflate(R.layout.fragment_sign_up, container, false);

        materialBtnSign = rootView.findViewById(R.id.materialBtnSign);
        materialPwd = rootView.findViewById(R.id.materialPwd);
        materialUser = rootView.findViewById(R.id.materialUser);



        materialUser.setTranslationX(800);
        materialPwd.setTranslationX(800);
        materialBtnSign.setTranslationX(800);


        materialUser.setAlpha(v);
        materialPwd.setAlpha(v);
        materialBtnSign.setAlpha(v);


        materialUser.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(350).start();
        materialPwd.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(450).start();
        materialBtnSign.animate().translationX(0).alpha(1).setDuration(800).setStartDelay(500).start();

        return rootView;
    }
}