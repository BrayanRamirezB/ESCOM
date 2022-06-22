package com.example.sensores5;

import java.util.*;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.hardware.*;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends Activity{
    TextView jtv;
    Sensor s;
    SensorManager sm;
    List <Sensor> l;
    String c, v;
    int n, t;
    float p, r, d;
    private ListView jlv;
    private ArrayList<String> names;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);

        jtv = (TextView) findViewById(R.id.xtv);
        jlv = (ListView) findViewById(R.id.xlv);

        sm = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
        l = sm.getSensorList(Sensor.TYPE_ALL);
        n = l.size();
        jtv.append("\nSensores detectados: " + n + "\n");
        names = new ArrayList<String>();

        for(int i=0; i<n; i++){
            s = l.get(i);
            t = s.getType();
            c = s.getName();
            v = s.getVendor();
            p = s.getPower();
            r = s.getResolution();
            d = s.getMaximumRange();
            names.add("Tipo de sensor: " + t + ", " + c);
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names);
        jlv.setAdapter(adapter);
    }
}
