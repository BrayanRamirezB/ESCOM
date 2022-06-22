package com.example.tarea4ejercicio2;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.*;
import android.content.Intent;
import android.widget.*;

public class MainActivity extends Activity {

    EditText jet1, jet2, jet3;
    Button jbn;
    Bundle bd1;
    Intent itn;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jet1 = (EditText) findViewById(R.id.xet1);
        jet2 = (EditText) findViewById(R.id.xet2);
        jet3 = (EditText) findViewById(R.id.xet3);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd1.putString("CA", jet1.getText().toString());
                bd1.putString("CB", jet2.getText().toString());
                bd1.putString("CC", jet3.getText().toString());
                itn.putExtras(bd1);
                startActivity(itn);
            }
        });
    }
}