package com.example.sensores4;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;

public class MainActivity extends Activity implements SensorEventListener {
    private SensorManager sensorManager;
    private Sensor proximity;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        proximity = sensorManager.getDefaultSensor(Sensor.TYPE_PROXIMITY);
    }

    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this, proximity, SensorManager.SENSOR_DELAY_NORMAL);
    }

    public final void onAccuracyChanged(Sensor sensor, int accuracy) {}

    public final void onSensorChanged(SensorEvent event) {
        float distance = event.values[0];

        if(distance < proximity.getMaximumRange()) {
            // Detecta algo cerca
            getWindow().getDecorView().setBackgroundColor(Color.RED);
            Intent itn = new Intent(MainActivity.this, Activity2.class);
            startActivity(itn);
        } else {
            // Nada esta cerca
            getWindow().getDecorView().setBackgroundColor(Color.GREEN);
        }
    }
}