package com.example.fragmentos2;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;

public class DetalleActivity extends AppCompatActivity {
    public static final String EXTRA_TEXTO = "com.example.escom.fragmentos.EXTRA_TEXTO";
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_detalle);
        FragmentDetalle fd = (FragmentDetalle) getSupportFragmentManager().findFragmentById(R.id.FrgDetalle);
        fd.mostrarDetalle(getIntent().getStringExtra(EXTRA_TEXTO));
    }
}