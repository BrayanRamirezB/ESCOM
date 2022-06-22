package com.example.fragmentos2;

import com.example.fragmentos2.FragmentListado.GruposListener;
import android.content.Intent;
import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements GruposListener {
    FragmentListado fl;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        fl = (FragmentListado)getSupportFragmentManager().findFragmentById(R.id.FrgListado);
        fl.setGruposListener(this);
    }

    public void onGrupoSeleccionado(Grupo c) {
        boolean bo = (getSupportFragmentManager().findFragmentById(R.id.FrgDetalle) !=
                null);
        if(bo) {
            ((FragmentDetalle) getSupportFragmentManager().findFragmentById(
                    R.id.FrgDetalle) ).mostrarDetalle( c.getTexto() );
        }
        else {
            Intent i = new Intent(this, DetalleActivity.class);
            i.putExtra(DetalleActivity.EXTRA_TEXTO, c.getTexto());
            startActivity(i);
        }
    }
}
