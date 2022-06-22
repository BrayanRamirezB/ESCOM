package com.example.conjetura;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.*;
import android.widget.*;
import java.util.ArrayList;

public class MainActivity extends Activity {

    EditText jed1;
    TextView jtv;
    Button jbn;
    String numero;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jed1 = (EditText) findViewById(R.id.xed1);
        jtv = (TextView) findViewById(R.id.xtv);
        jbn = (Button) findViewById(R.id.xbn);

        jbn.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                String asc, des;
                int res = 0;
                numero = jed1.getText().toString();

                if(((numero.length()) == 3)||((numero.length()) == 4)){
                    while(res != 495 && res != 6174){
                        des = descendente(numero);
                        asc = ascendente(numero);
                        res = restar(des,asc);
                        numero = ""+res;
                        jtv.append("\n" + des + " - " + asc + " = " + res);
                    }
                }else{
                    jtv.setText("Ingresa un número valido.");
                }
            }
        });

    }

    public String descendente (String s){
        String n = "";
        int i, j, aux;
        ArrayList<Integer> a = new ArrayList<Integer>();

        for(i = 0; i<s.length();i++)
            a.add(Integer.parseInt(String.valueOf(s.charAt(i))));

        for(i = 0; i<s.length()-1;i++){
            for(j=i+1;j < s.length(); j++){
                if(a.get(i) < a.get(j)){
                    aux = a.get(i);
                    a.set(i,a.get(j));
                    a.set(j,aux);
                }
            }
        }

        for(i = 0; i<s.length();i++)
            n = n + a.get(i);

        return n;
    }

    public String ascendente (String s){
        String n = "";
        int i, j, aux;
        ArrayList<Integer> a = new ArrayList<Integer>();

        for(i = 0; i<s.length();i++)
            a.add(Integer.parseInt(String.valueOf(s.charAt(i))));

        for(i = 0; i<s.length()-1;i++){
            for(j=i+1;j < s.length(); j++){
                if(a.get(i) > a.get(j)){
                    aux = a.get(i);
                    a.set(i,a.get(j));
                    a.set(j,aux);
                }
            }
        }

        for(i = 0; i<s.length();i++)
            n = n + a.get(i);

        return n;
    }

    public Integer  restar (String d, String a){
        int D = Integer.parseInt(d);
        int A =  Integer.parseInt(a);
        return (D-A);
    }
}