package com.example.tarea28ejemplo1;

import android.app.*;
import android.os.*;
import android.view.View;
import android.view.View.*;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener {
    private EditText jet1;
    private Button jbn1;
    private TextView jtv2;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jet1 = (EditText) findViewById(R.id.xet1);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn1.setOnClickListener(this);
        jtv2 = (TextView) findViewById(R.id.xtv2);
    }

    public void onClick(View v) {
        try{
            final int n = Integer.parseInt(jet1.getText().toString());
            new Thread(new Runnable(){
                public void run() {
                    try {
                        runOnUiThread(new Runnable() {
                            @Override public void run() {
                                jtv2.setText("El hilo se bloquea durante "+ n + " segundos");
                            }
                        });
                        Thread.sleep(n*1000);
                    } catch (InterruptedException ie) {}
                }
            }).start();
        }catch (NumberFormatException e){
            Toast.makeText(this,"ingresar segundos...", Toast.LENGTH_SHORT).show();
        }
    }
}