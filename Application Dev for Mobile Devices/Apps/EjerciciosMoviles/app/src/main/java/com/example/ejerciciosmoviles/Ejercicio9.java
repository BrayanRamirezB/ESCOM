package com.example.ejerciciosmoviles;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;

public class Ejercicio9 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ejercicio9);
    }

    public class DbmsSQLiteHelper extends SQLiteOpenHelper {
        String sqlCreate = "CREATE TABLE Imagenes (id INTEGER, nombre TEXT)";

        public DbmsSQLiteHelper(Context c, String s, SQLiteDatabase.CursorFactory cf, int v){
            super(c, s, cf, v);
        }

        public void onCreate(SQLiteDatabase db){
            db.execSQL(sqlCreate);
        }

        public void onUpgrade(SQLiteDatabase sqld, int ov, int nv) {
            sqld.execSQL("DROP TABLE IF EXISTS Contactos");
            sqld.execSQL(sqlCreate);
        }
    }
}