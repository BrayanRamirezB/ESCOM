package com.example.listas2;

import android.app.Activity;
import android.os.Bundle;
import java.util.*;
import android.widget.ListView;

public class MainActivity extends Activity {

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        final ListView lv = (ListView) findViewById(R.id.xlv1);
        final NuevaEntradaAdapter nea = new NuevaEntradaAdapter(this,
                R.layout.activity_nueva_entrada);
        lv.setAdapter(nea);
        for(final NuevaEntrada i : getEntradas()) {
            nea.add(i);
        }
    }
    private List<NuevaEntrada> getEntradas() {
        final List<NuevaEntrada> datos = new ArrayList<NuevaEntrada>();
        for(int i = 1; i < 31; i++) {
            datos.add(
                    new NuevaEntrada(
                            "Datos de Entrada " + i, "Alejandro ESCOM " + i,
                            new GregorianCalendar(2016, 12, i).getTime(),
                            i % 2 == 0 ? R.drawable.icon_1 : R.drawable.icon_2
                    )
            );
        }
        return datos;
    }
}