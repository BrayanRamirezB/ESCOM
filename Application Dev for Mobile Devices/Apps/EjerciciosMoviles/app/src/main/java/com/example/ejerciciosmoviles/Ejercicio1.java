package com.example.ejerciciosmoviles;

import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.View;
import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;

public class Ejercicio1 extends Activity {
    private Timer timer;
    private  Calendar mCalendar;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ejercicio1);
        setContentView(new Lienzo(this));
    }

    public class Lienzo extends View {
        Paint p = new Paint();

        public  Lienzo (Context c){
            super(c);
        }

        protected void onDraw(Canvas c){
            super.onDraw(c);
            c.drawRGB(0,0,0);
            p.setColor(Color.BLUE);
            timer = new Timer();

            timer.schedule(new TimerTask() {
                public void run() {
                    mCalendar = Calendar.getInstance();
                    int hour = mCalendar.get(Calendar.HOUR_OF_DAY);// HOUR son 12 horas HOUR_OF_DAY son 24 horas
                    int minute = mCalendar.get(Calendar.MINUTE);//minuto
                    int second = mCalendar.get(Calendar.SECOND) + 1;//Segundos
                    if (second == 60) {
                        minute += 1;
                        second = 0;
                    }
                    if (minute == 60){
                        hour += 1;
                        minute = 0;
                    }
                    if (hour == 12){
                        hour = 0;
                    }
                    String time = String.format("%d:%02d:%02d", hour, minute, second);
                    mCalendar.set(Calendar.SECOND, second);
                    mCalendar.set(Calendar.MINUTE, minute);
                    mCalendar.set(Calendar.HOUR_OF_DAY, hour);

                    p.setTextSize(100);
                    p.setTypeface(Typeface.SERIF);
                    c.drawText(time,200,600,p);
                }
            },0,1000);
        }
    }

    protected void onDestroy() {
        super.onDestroy();
        if(timer!=null){
            timer.cancel();// Cerrar temporizador
        }
    }
}