package com.example.ejerciciosmoviles;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.view.View;
import android.view.View.*;

public class MainActivity extends Activity {
    Button jbn1, jbn2,jbn3, jbn4, jbn5, jbn6, jbn7, jbn8, jbn9, jbn10;
    Intent itn;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn3 = (Button) findViewById(R.id.xbn3);
        jbn4 = (Button) findViewById(R.id.xbn4);
        jbn5 = (Button) findViewById(R.id.xbn5);
        jbn6 = (Button) findViewById(R.id.xbn6);
        jbn7 = (Button) findViewById(R.id.xbn7);
        jbn8 = (Button) findViewById(R.id.xbn8);
        jbn9 = (Button) findViewById(R.id.xbn9);
        jbn10 = (Button) findViewById(R.id.xbn10);

        jbn1.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio1.class);
                startActivity(itn);
            }
        });

        jbn2.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio2.class);
                startActivity(itn);
            }
        });

        jbn3.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio3.class);
                startActivity(itn);
            }
        });

        jbn4.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio4.class);
                startActivity(itn);
            }
        });

        jbn5.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio5.class);
                startActivity(itn);
            }
        });

        jbn6.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio6.class);
                startActivity(itn);
            }
        });

        jbn7.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio7.class);
                startActivity(itn);
            }
        });

        jbn8.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio8.class);
                startActivity(itn);
            }
        });

        jbn9.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio9.class);
                startActivity(itn);
            }
        });

        jbn10.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                itn = new Intent(MainActivity.this, Ejercicio10.class);
                startActivity(itn);
            }
        });
    }
}