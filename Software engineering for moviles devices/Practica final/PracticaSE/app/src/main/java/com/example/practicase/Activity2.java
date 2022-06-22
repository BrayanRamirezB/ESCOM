package com.example.practicase;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.*;
import android.widget.*;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toolbar;
import android.widget.AdapterView.*;

public class Activity2 extends AppCompatActivity {
    Toolbar jtb;
    Button jbn;
    Bundle bdl, bdl1;
    Spinner jsp1, jsp2;
    String tamaño, tema;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);
        jtb =(Toolbar) findViewById(R.id.xtb);
        jsp1 = (Spinner) findViewById(R.id.xsp1);
        jsp2 = (Spinner) findViewById(R.id.xsp2);
        jbn = (Button) findViewById(R.id.xbn);

        bdl = getIntent().getExtras();
        jtb.setTitle(bdl.getString("NOMBRE"));

        jsp1.setOnItemSelectedListener(new OnItemSelectedListener() {
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                tema = jsp1.getSelectedItem().toString();
            }

            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        jsp2.setOnItemSelectedListener(new OnItemSelectedListener() {
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                tamaño = jsp2.getSelectedItem().toString();
            }

            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                if(tamaño.equals("4x4")){
                    Intent itn = new Intent(Activity2.this, Activity3.class);
                    bdl1 = new Bundle();
                    bdl1.putString("NOMBRE", bdl.getString("NOMBRE"));
                    bdl1.putString("TEMA", tema);
                    itn.putExtras(bdl1);
                    startActivity(itn);
                }else{
                    Intent itn = new Intent(Activity2.this, Activity4.class);
                    bdl1 = new Bundle();
                    bdl1.putString("NOMBRE", bdl.getString("NOMBRE"));
                    bdl1.putString("TEMA", tema);
                    itn.putExtras(bdl1);
                    startActivity(itn);
                }
            }
        });
    }
}