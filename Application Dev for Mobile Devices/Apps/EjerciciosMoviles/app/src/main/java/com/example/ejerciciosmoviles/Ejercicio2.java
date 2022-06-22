package com.example.ejerciciosmoviles;

import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.view.View;


public class Ejercicio2 extends Activity {

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new Ejercicio2.Lienzo(this));
    }

    public class Lienzo extends View {
        Paint p = new Paint();

        public  Lienzo (Context c){
            super(c);
        }

        protected void onDraw(Canvas c){
            super.onDraw(c);
            //c.drawRGB(0,0,0);
            c.drawColor(Color.BLUE);
            p.setStyle(Paint.Style.STROKE);
            p.setAntiAlias(true);
            p.setStrokeWidth(5);
            p.setColor(Color.RED);
            c.drawCircle(360,600,340,p);

            // Marca de la señal
            p.setStyle(Paint.Style.STROKE);
            p.setAntiAlias(true);
            p.setStrokeWidth(3);
            p.setColor(Color.WHITE);

            int rotateAngel = 360 / 60;
            int txt;
            String time;
            for (int i = 0; i < 60; i++){

                if (i / 5 == 0){
                    txt = 12;
                }else {
                    txt = i / 5;
                }
                time = String.valueOf(txt);

                if (i % 5 == 0){
                    // Gran escala
                    p.setStrokeWidth(5);
                    p.setTextSize(30);
                    c.drawLine(
                            360,600-340,
                            360,600-340+30,
                            p
                    );

                    c.drawText(
                            time,
                            360 - p.measureText(time) / 2,
                            600-340+60,
                            p
                    );
                }else {
                    // pequeña escala
                    p.setStrokeWidth(3);
                    p.setTextSize(15);
                    c.drawLine(
                            360,600-340,
                            360,600-340+15,
                            p
                    );
                }
                c.rotate(rotateAngel,360,600);
            }//for

            // Puntero
            p.setStyle(Paint.Style.STROKE);
            p.setAntiAlias(true);

            // manecilla de hora
            c.translate(360,600);
            p.setStrokeWidth(15);
            p.setColor(Color.BLACK);
            c.drawLine(0,0,0,-1200 / 6,p);
            // minutero
            p.setStrokeWidth(10);
            p.setColor(Color.RED);
            c.drawLine(0,0,0,-1200/5,p);
            // segunda mano
            p.setStrokeWidth(5);
            p.setColor(Color.DKGRAY);
            c.drawLine(0,0,0,-600 / 2,p);
        }
    }
}