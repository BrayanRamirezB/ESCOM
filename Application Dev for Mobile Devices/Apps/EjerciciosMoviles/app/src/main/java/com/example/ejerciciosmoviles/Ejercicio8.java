package com.example.ejerciciosmoviles;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.pm.ActivityInfo;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;

public class Ejercicio8 extends AppCompatActivity {
    MiPelota dibujo;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        dibujo = new MiPelota(this);
        setContentView(dibujo);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
    }

    public class MiPelota extends View implements SensorEventListener {
        Paint p = new Paint();
        int alto,ancho;
        int tam = 80;
        int borde=12;
        float ejex=0,ejey=0,ejez=0;
        String x,y,z;

        public MiPelota(Context context) {
            super(context);
            SensorManager smAdministrador = (SensorManager) getContext().getSystemService(Context.SENSOR_SERVICE);
            Sensor snsRotacion = smAdministrador.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
            smAdministrador.registerListener(this,snsRotacion,SensorManager.SENSOR_DELAY_FASTEST);
            Display pantalla = ((WindowManager) getContext().getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
            ancho = pantalla.getWidth();
            alto = pantalla.getHeight();
        }

        public void onSensorChanged(SensorEvent cambio) {
            ejex = cambio.values[0];
            x=Float.toString(ejex);
            if(ejex<(tam+borde)){
                ejex=(tam+borde);
            } else if (ejex > (ancho-(tam+borde))){
                ejex=ancho-(tam+borde);
            }
            ejey+=cambio.values[1];
            y=Float.toString(ejey);
            if(ejey<(tam+borde)){
                ejey=tam+borde;
            } else if (ejey>(alto-tam-170)){
                ejey = alto-tam-170;
            }
            ejez=cambio.values[2];
            z = String.format("%.2f",ejez);
            invalidate();
        }

        public void onAccuracyChanged(Sensor sensor, int i) {
        }

        public void onDraw(Canvas lienzo){
            p.setColor(Color.BLUE);
            lienzo.drawCircle(ejex,ejey,ejez+tam,p);
        }
    }
}

