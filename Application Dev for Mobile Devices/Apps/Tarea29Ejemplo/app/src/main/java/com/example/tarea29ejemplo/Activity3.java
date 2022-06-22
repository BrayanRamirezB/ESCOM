package com.example.tarea29ejemplo;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.view.*;
import android.view.View.*;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.*;

public class Activity3 extends AppCompatActivity {
    EditText jet1, jet2, jet3, jet4;
    Button jbn1, jbn2, jbn3;
    SQLiteDatabase sqld;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_3);

        jet1 = (EditText) findViewById(R.id.xet1);
        jet2 = (EditText) findViewById(R.id.xet2);
        jet3 = (EditText) findViewById(R.id.xet3);
        jet4 = (EditText) findViewById(R.id.xet4);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn3 = (Button) findViewById(R.id.xbn3);

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBmsg", null, 1);
        sqld = dsqlh.getWritableDatabase();

        //Agregar un dato
        jbn1.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String nombre = jet1.getText().toString();
                String telefono = jet2.getText().toString();
                String email = jet3.getText().toString();
                String telefonia = jet4.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("nombre", nombre);
                cv.put("telefono", telefono);
                cv.put("email", email);
                cv.put("telefonia", telefonia);
                sqld.insert("msg", null, cv);
                jet1.setText("");
                jet2.setText("");
                jet3.setText("");
                jet4.setText("");
            }
        });

        jbn2.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String nombre = jet1.getText().toString();
                String telefono = jet2.getText().toString();
                sqld.delete("msg","nombre=? and telefono=?",new String[]{nombre,telefono});
                jet1.setText("");
                jet2.setText("");
                jet3.setText("");
                jet4.setText("");
            }
        });

        //Actualizar datos con el numero
        jbn3.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String nombre = jet1.getText().toString();
                String telefono = jet2.getText().toString();
                String email = jet3.getText().toString();
                String telefonia = jet4.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("nombre", nombre);
                cv.put("telefono", telefono);
                cv.put("email", email);
                cv.put("telefonia", telefonia);
                sqld.update("msg",cv,"email=?",new String[]{nombre, telefono, telefonia});
                jet1.setText("");
                jet2.setText("");
                jet3.setText("");
                jet4.setText("");
            }
        });
    }
}