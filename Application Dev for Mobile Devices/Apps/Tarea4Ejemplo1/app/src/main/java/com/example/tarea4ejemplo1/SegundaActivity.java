package com.example.tarea4ejemplo1;

import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SegundaActivity extends Activity {

    EditText jet;
    Bundle bd1;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_segunda);
        jet = (EditText) findViewById(R.id.xet1);
        bd1 = getIntent().getExtras();
        jet.append("Hola "+ bd1.getString("NOMBRE"));
    }
}