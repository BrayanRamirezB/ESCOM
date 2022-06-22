package com.example.tarea8ejercicio2;

import java.io.*;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity {
    EditText jet1;
    static final int READ_BLOCK_SIZE = 100;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jet1 = (EditText) findViewById(R.id.xet1);
    }
    public void guardar(View v){
        String str = jet1.getText().toString();
        try{
            FileOutputStream fos = openFileOutput("misdatos.txt", MODE_PRIVATE);
            OutputStreamWriter osw = new OutputStreamWriter(fos);
            osw.write(str);
            osw.flush();
            osw.close();
            Toast.makeText(getBaseContext(), "Archivo guardado",
                    Toast.LENGTH_SHORT).show();
            jet1.setText("");
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }
    public void abrir(View v){
        try{
            FileInputStream fis = openFileInput("misdatos.txt");
            InputStreamReader isr = new InputStreamReader(fis);
            char[] buffer = new char[READ_BLOCK_SIZE];
            String s = "";
            int n;
            while((n = isr.read(buffer)) > 0){
                String readString = String.copyValueOf(buffer, 0, n);
                s += readString;
                buffer = new char[READ_BLOCK_SIZE];
            }
            jet1.setText(s);
            Toast.makeText(getBaseContext(), "Archivo abierto",
                    Toast.LENGTH_SHORT).show();
            isr.close();
        }catch (IOException ex){
            ex.printStackTrace();
        }
    }
}


