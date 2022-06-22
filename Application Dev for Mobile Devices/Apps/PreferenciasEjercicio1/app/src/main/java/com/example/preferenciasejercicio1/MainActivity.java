package com.example.preferenciasejercicio1;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.*;
import android.app.*;
import android.view.View;
import android.view.View.*;
import android.widget.*;

public class MainActivity extends Activity{
    SharedPreferences sp;
    EditText jetx, jety;
    float latitud, longitud;
    Button jbn;
    Bundle bdl;
    Intent itn;

    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jetx = (EditText) findViewById(R.id.xetx);
        jety = (EditText) findViewById(R.id.xety);
        sp = getSharedPreferences("preferencias_Ejercicio1", Context.MODE_PRIVATE);
        latitud = sp.getFloat("Latitud", 0);
        longitud = sp.getFloat("Longitud", 0);
        jetx.setText("" + latitud);
        jety.setText("" + longitud);

        //Intent
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn = new Intent(MainActivity.this, SegundaActivity.class);
                bdl = new Bundle();
                bdl.putString("LATITUD", jetx.getText().toString());
                bdl.putString("LONGITUD", jety.getText().toString());
                itn.putExtras(bdl);
                startActivity(itn);
            }
        });
    }

    protected void onPause(){
        super.onPause();
        latitud = Float.parseFloat(jetx.getText().toString());
        longitud = Float.parseFloat(jety.getText().toString());
        SharedPreferences.Editor miEditor = sp.edit();
        miEditor.putFloat("Latitud", latitud);
        miEditor.putFloat("Longitud", longitud);
        miEditor.commit();
        Toast.makeText(this, "Preferencias guardadas", Toast.LENGTH_LONG).show();
    }
}
