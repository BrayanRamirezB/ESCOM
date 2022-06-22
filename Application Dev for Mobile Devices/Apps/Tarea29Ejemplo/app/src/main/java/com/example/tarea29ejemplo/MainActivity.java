package com.example.tarea29ejemplo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.view.*;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    Button jbn1, jbn2;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);

        jbn1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                Intent itn = new Intent(MainActivity.this, Activity2.class);
                startActivity(itn);
            }
        });

        jbn2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                Intent itn = new Intent(MainActivity.this, Activity4.class);
                startActivity(itn);
            }
        });

    }
}