package com.example.cubo;

import android.app.Activity;
import android.os.Bundle;
import android.widget.FrameLayout;

public class MainActivity extends Activity {

    FrameLayout cubo1, cubo2;
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Cubo uno = new Cubo(this);
        Cubo dos = new Cubo(this);
        cubo1 = (FrameLayout)findViewById(R.id.izquierda);
        cubo2 = (FrameLayout)findViewById(R.id.derecha);
        cubo1.addView(uno);
        cubo2.addView(dos);
    }
}