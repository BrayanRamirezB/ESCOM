package com.example.preferencias;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.*;
import android.app.*;
import android.widget.*;

public class MainActivity extends Activity{
    SharedPreferences sp;
    EditText jetn, jetx, jety;
    String s;
    float x, y;

    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jetn = (EditText) findViewById(R.id.xetn);
        jetx = (EditText) findViewById(R.id.xetx);
        jety = (EditText) findViewById(R.id.xety);
        sp = getSharedPreferences("preferencias", Context.MODE_PRIVATE);
        s = sp.getString("titulo", "ESCOM");
        x = sp.getFloat("x", 0);
        y = sp.getFloat("y", 0);
        jetn.setText(s);
        jetx.setText("" + x);
        jety.setText("" + y);
    }

    protected void onPause(){
        super.onPause();
        s = jetn.getText().toString();
        x = Float.parseFloat(jetx.getText().toString());
        y = Float.parseFloat(jety.getText().toString());
        SharedPreferences.Editor miEditor = sp.edit();
        miEditor.putString("titulo", s);
        miEditor.putFloat("x", x);
        miEditor.putFloat("y", y);
        miEditor.commit();
        Toast.makeText(this, "Preferencias guardadas", Toast.LENGTH_LONG).show();
    }
}
