package com.example.tarea9ejemplo1;

import android.os.Bundle;
import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity {
    EditText jetI, jetN;
    Button jbnA, jbnL, jbnB, jbnCN, jbnCI;
    TextView jtvL;
    SQLiteDatabase sqld;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jetI = (EditText) findViewById(R.id.xetI);
        jetN = (EditText) findViewById(R.id.xetN);
        jbnA = (Button) findViewById(R.id.xbnA);
        jbnL = (Button) findViewById(R.id.xbnL);
        jbnB = (Button) findViewById(R.id.xbnB);
        jbnCN = (Button) findViewById(R.id.xbnCN);
        jbnCI = (Button) findViewById(R.id.xbnCI);
        jtvL = (TextView) findViewById(R.id.xtvL);

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBContactos", null, 1);
        sqld = dsqlh.getWritableDatabase();

        //Agregar un dato
        jbnA.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id = jetI.getText().toString();
                String nombre = jetN.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("id", id);
                cv.put("nombre", nombre);
                sqld.insert("Contactos", null, cv);
                jetI.setText("");
                jetN.setText("");
            }
        });

        //Borrar un dato
        jbnB.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id = jetI.getText().toString();
                String nombre = jetN.getText().toString();
                sqld.delete("Contactos","id=? and nombre=?",new String[]{id,nombre});
                jetI.setText("");
                jetN.setText("");
            }
        });

        //Actualizar nombre
        jbnCN.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id = jetI.getText().toString();
                String nombre = jetN.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("nombre",nombre);
                sqld.update("Contactos",cv,"id=?",new String[]{id});
                jetI.setText("");
                jetN.setText("");
            }
        });

        //Actualizar id
        jbnCI.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id = jetI.getText().toString();
                String nombre = jetN.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("id",id);
                sqld.update("Contactos",cv,"nombre=?",new String[]{nombre});
                jetI.setText("");
                jetN.setText("");
            }
        });

        //Ver los datos
        jbnL.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String id, nombre;
                Cursor c = sqld.rawQuery("SELECT id,nombre FROM Contactos", null);
                jtvL.setText("");
                if (c.moveToFirst()) {
                    do {
                        id = c.getString(0);
                        nombre = c.getString(1);
                        jtvL.append(" " + id + "\t" + nombre + "\n");
                    } while (c.moveToNext());
                }
            }
        });
    }
}