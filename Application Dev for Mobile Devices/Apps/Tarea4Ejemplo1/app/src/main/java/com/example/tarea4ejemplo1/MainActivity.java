package com.example.tarea4ejemplo1;

import android.os.Bundle;
import android.app.Activity;
import android.view.View;
import android.view.View.*;
import android.content.Intent;
import android.widget.*;

public class MainActivity extends Activity {
    EditText jet;
    Button jbn;
    Bundle bd1;
    Intent itn;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jet = (EditText) findViewById(R.id.xet);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View arg0) {
                itn = new Intent(MainActivity.this, SegundaActivity.class);
                bd1 = new Bundle();
                bd1.putString("NOMBRE", jet.getText().toString());
                itn.putExtras(bd1);
                startActivity(itn);
            }
        });
    }
}