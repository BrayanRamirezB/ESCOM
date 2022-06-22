package com.example.ejerciciosmoviles;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AppCompatActivity;

public class Ejercicio10 extends AppCompatActivity implements View.OnClickListener {
    int turno,contador;
    Button Btn_1,Btn_2,Btn_3,Btn_4,Btn_5,Btn_6,Btn_7,Btn_8,Btn_9;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        super.setContentView(R.layout.activity_ejercicio10);

        //Jalo las referencias
        Btn_1=(Button)(findViewById(R.id.Btn_1));
        Btn_2=(Button)(findViewById(R.id.Btn_2));
        Btn_3=(Button)(findViewById(R.id.Btn_3));
        Btn_4=(Button)(findViewById(R.id.Btn_4));
        Btn_5=(Button)(findViewById(R.id.Btn_5));
        Btn_6=(Button)(findViewById(R.id.Btn_6));
        Btn_7=(Button)(findViewById(R.id.Btn_7));
        Btn_8=(Button)(findViewById(R.id.Btn_8));
        Btn_9=(Button)(findViewById(R.id.Btn_9));

        //Estamos haciendo que mis botones los escuche el onClick
        Btn_1.setOnClickListener(this);
        Btn_2.setOnClickListener(this);
        Btn_3.setOnClickListener(this);
        Btn_4.setOnClickListener(this);
        Btn_5.setOnClickListener(this);
        Btn_6.setOnClickListener(this);
        Btn_7.setOnClickListener(this);
        Btn_8.setOnClickListener(this);
        Btn_9.setOnClickListener(this);
    }

    public void onClick(View v) {
        contador++;
        turno = contador%2;
        //Jugador 1 X
        if(turno == 1){
            imprimirXO('x', v);
        }
        //Jugador 2 O
        else{
            imprimirXO('o', v);
        }
    }//Fin del onClick

    public void imprimirXO(char letra, View v){

        if(v.getId() == R.id.Btn_1){
            Btn_1.setText(letra+"");
            Btn_1.setEnabled(false);
        }//Cierro el IF
        else if(v.getId() == R.id.Btn_2){
            Btn_2.setText(letra+"");
            Btn_2.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_3){
            Btn_3.setText(letra+"");
            Btn_3.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_4){
            Btn_4.setText(letra+"");
            Btn_4.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_5){
            Btn_5.setText(letra+"");
            Btn_5.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_6){
            Btn_6.setText(letra+"");
            Btn_6.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_7){
            Btn_7.setText(letra+"");
            Btn_7.setEnabled(false);
        }
        else if(v.getId() == R.id.Btn_8){
            Btn_8.setText(letra+"");
            Btn_8.setEnabled(false);
        }
        else{
            Btn_9.setText(letra+"");
            Btn_9.setEnabled(false);
        }
    }
}