package com.example.tarea4ejercicio2;

import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SegundaActivity extends Activity {

    EditText jet1, jet2;
    Bundle bd1;
    int a, b, c;
    double x1, x2, d;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_segunda);
        jet1 = (EditText) findViewById(R.id.xet1);
        jet2 = (EditText) findViewById(R.id.xet2);
        bd1 = getIntent().getExtras();
        a = Integer.parseInt(bd1.getString("CA"));
        b = Integer.parseInt(bd1.getString("CB"));
        c = Integer.parseInt(bd1.getString("CC"));

        d = Math.sqrt((b*b)-(4*a*c));
        x1 = (d-b)/(2*a);
        x2 = (-d-b)/(2*a);

        jet1.append("x1 = " + x1);
        jet2.append("x2 = " + x2);
    }
}