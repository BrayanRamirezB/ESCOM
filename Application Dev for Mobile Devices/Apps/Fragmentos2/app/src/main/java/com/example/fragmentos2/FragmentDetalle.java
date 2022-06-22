package com.example.fragmentos2;

import android.os.Bundle;
import androidx.fragment.app.*;
import android.view.*;
import android.widget.TextView;

public class FragmentDetalle extends Fragment {

    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle b) {
        return inflater.inflate(R.layout.activity_fragment_detalle, container, false);
    }
    public void mostrarDetalle(String texto) {
        TextView tv = (TextView)getView().findViewById(R.id.xtvDetalle);
        tv.setText(texto);
    }
}