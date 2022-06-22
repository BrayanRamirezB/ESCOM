package com.example.cuadromagico;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends Activity implements OnClickListener {
    Button jbn1;
    EditText jet1;
    Bundle bdl;
    Intent itn;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jet1 = findViewById(R.id.xet1);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn1.setOnClickListener(this);
    }

    public void onClick(View v) {
        itn = new Intent(MainActivity.this,CuadroMagico.class);
        bdl = new Bundle();
        itn.putExtra("Dato", jet1.getText().toString());
        startActivity(itn);
    }
}