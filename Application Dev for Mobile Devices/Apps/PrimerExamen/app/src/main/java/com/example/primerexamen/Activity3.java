package com.example.primerexamen;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.view.View;
import android.view.View.*;

public class Activity3 extends Activity {
    SQLiteDatabase sqld;
    EditText jet1,jet2;
    TextView jtv;
    Button jbn1,jbn2,jbn3;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_3);

        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn3 = (Button) findViewById(R.id.xbn3);
        jet1 = (EditText) findViewById(R.id.xet1);
        jet2 = (EditText) findViewById(R.id.xet2);
        jtv = (TextView) findViewById(R.id.xtv);

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBbd", null, 1);
        sqld = dsqlh.getWritableDatabase();

        jbn1.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String nombre = jet1.getText().toString();
                String valor = jet2.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("nombre", nombre);
                cv.put("valor", valor);
                sqld.insert("bd", null, cv);
                jet1.setText("");
                jet2.setText("");

                nombre = "";
                valor = "";
                Cursor c = sqld.rawQuery("SELECT nombre, valor FROM bd", null);
                jtv.setText("");
                if (c.moveToFirst()) {
                    do {
                        nombre = c.getString(0);
                        valor = c.getString(1);
                        jtv.append(" " + nombre + "\t" + valor + "\n");
                    } while (c.moveToNext());
                }
            }
        });

        jbn2.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                String nombre = jet1.getText().toString();
                String valor = jet2.getText().toString();
                sqld.delete("bd","nombre=? and valor=?",new String[]{nombre,valor});
                jet1.setText("");
                jet2.setText("");

                nombre = "";
                valor = "";
                Cursor c = sqld.rawQuery("SELECT nombre, valor FROM bd", null);
                jtv.setText("");
                if (c.moveToFirst()) {
                    do {
                        nombre = c.getString(0);
                        valor = c.getString(1);
                        jtv.append(" " + nombre + "\t" + valor + "\n");
                    } while (c.moveToNext());
                }
            }
        });

        jbn3.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                finishAffinity();
                System.exit(0);
            }
        });
    }
}