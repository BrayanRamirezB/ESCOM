package com.example.tarea19ejemplo;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class HistorialActivity extends AppCompatActivity {
    TextView jtv;
    Bundle bdl;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_historial);

        jtv = (TextView) findViewById(R.id.xtv);
        bdl = getIntent().getExtras();
        jtv.append(bdl.getString("Historial"));
    }
}