package com.example.numeros;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener {

    EditText jet1;
    Button jbn1;
    TextView jtv2;
    int n, m, f1 = 0, f2 = 1, f3 = 1;
    boolean primo = false, fibo = false;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        jet1 = (EditText) findViewById(R.id.xet1);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn1.setOnClickListener(this);
        jtv2 = (TextView) findViewById(R.id.xtv2);
    }

    public void onClick(View v){
        n = Integer.parseInt(jet1.getText().toString());

        //Determina si es maravilloso
        m = n;
        while (m != 1){
            if((m%2) == 0){
                m = m/2;
            }else{
                m = (m*3) + 1;
            }
            jtv2.append("\n" + m);
        }
        if(m == 1){
            jtv2.append("\n" + n + " Es un número maravilloso.");
        }else{
            jtv2.append("\n" + n + "No es un número maravilloso.");
        }

        //Determina si es primo
        for(int i = 2; i< n ;i++){
            if((n%i) == 0) {
                primo = true;
            }
        }
        if(!primo){
            jtv2.append("\n" + n + " es un número primo.");
        }else{
            jtv2.append("\n" + n + " no es un número primo.");
        }

        //Determina si es fibonacci
        while(f3 <= n){
            if(f3 == n){
                fibo = true;
            }
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        if(fibo){
            jtv2.append("\n" + n + " es número Fibonacci.");
        }else{
            jtv2.append("\n" + n + " no es número Fibonacci.");
        }
    }
}