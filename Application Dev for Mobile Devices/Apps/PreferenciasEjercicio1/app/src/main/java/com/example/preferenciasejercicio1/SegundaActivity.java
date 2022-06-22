package com.example.preferenciasejercicio1;

import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SegundaActivity extends Activity{
    EditText jetx, jety;
    Bundle bdl;

    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_segunda);
        jetx = (EditText) findViewById(R.id.xet1);
        jety = (EditText) findViewById(R.id.xet2);
        bdl = getIntent().getExtras();
        jetx.append(bdl.getString("LATITUD"));
        jety.append(bdl.getString("LONGITUD"));
    }
}