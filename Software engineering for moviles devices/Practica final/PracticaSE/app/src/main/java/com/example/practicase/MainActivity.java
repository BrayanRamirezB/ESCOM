package com.example.practicase;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.view.View.*;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    Button jbn;
    EditText jet;
    Bundle bdl;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jbn = (Button) findViewById(R.id.xbn);
        jet = (EditText) findViewById(R.id.xet);

        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                Intent itn = new Intent(MainActivity.this, Activity2.class);
                bdl = new Bundle();
                bdl.putString("NOMBRE", jet.getText().toString());
                itn.putExtras(bdl);
                startActivity(itn);
            }
        });
    }
}