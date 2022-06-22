package com.example.ejerciciosmoviles;

import android.app.Activity;
import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

public class Ejercicio5 extends Activity implements SensorEventListener {
    TextView jtv;
    private  static SensorManager sensorManager;
    private Sensor sensor;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ejercicio5);

        jtv = (TextView) findViewById(R.id.xtv);

        sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        sensor = sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
    }

    protected void onResume(){
        super.onResume();

        if(sensor != null){
            sensorManager.registerListener(this,sensor,SensorManager.SENSOR_DELAY_NORMAL);
        } else{
            Toast.makeText(this,"Not supported",Toast.LENGTH_SHORT).show();
            finish();
        }
    }

    protected void onPause(){
        super.onPause();
        sensorManager.unregisterListener(this);
    }

    public void onSensorChanged(SensorEvent sensorEvent) {
        float azimuth = Math.round(sensorEvent.values[0]);
        float pitch = Math.round(sensorEvent.values[1]);
        float roll = Math.round(sensorEvent.values[2]);

        double tesla = Math.sqrt((azimuth*azimuth)+(pitch*pitch)+(roll*roll));

        String text = String.format("%.0f",tesla);
        jtv.setText(text + " µT");
    }

    public void onAccuracyChanged(Sensor sensor, int i) {

    }
}