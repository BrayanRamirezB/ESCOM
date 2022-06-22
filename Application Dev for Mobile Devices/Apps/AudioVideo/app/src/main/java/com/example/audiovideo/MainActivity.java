package com.example.audiovideo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;

public class MainActivity extends Activity  {
    Button jbn1, jbn2, jbn3, jbn4,jbn5;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn3 = (Button) findViewById(R.id.xbn3);
        jbn4 = (Button) findViewById(R.id.xbn4);
        jbn5 = (Button) findViewById(R.id.xbn5);



        jbn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent myInten = new Intent(MainActivity.this,Second.class);
                Bundle bdl = new Bundle();
                bdl.putString("ID", "c1");
                myInten.putExtras(bdl);
                startActivity(myInten);
            }
        });

        jbn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent myInten = new Intent(MainActivity.this,Second.class);
                Bundle bdl = new Bundle();
                bdl.putString("ID", "c2");
                myInten.putExtras(bdl);
                startActivity(myInten);
            }
        });

        jbn3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent myInten = new Intent(MainActivity.this,Second.class);
                Bundle bdl = new Bundle();
                bdl.putString("ID", "c3");
                myInten.putExtras(bdl);
                startActivity(myInten);
            }
        });

        jbn4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent myInten = new Intent(MainActivity.this,Second.class);
                Bundle bdl = new Bundle();
                bdl.putString("ID", "c4");
                myInten.putExtras(bdl);
                startActivity(myInten);
            }
        });
        jbn5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent myInten = new Intent(MainActivity.this,Second.class);
                Bundle bdl = new Bundle();
                bdl.putString("ID", "this_is_love");
                myInten.putExtras(bdl);
                startActivity(myInten);
            }
        });
    }
}