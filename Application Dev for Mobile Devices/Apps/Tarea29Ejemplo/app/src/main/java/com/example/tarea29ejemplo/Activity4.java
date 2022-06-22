package com.example.tarea29ejemplo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;
import java.util.ArrayList;

public class Activity4 extends AppCompatActivity {
    EditText jet;
    Button jbn1, jbn2;
    Spinner jsp;
    String nombre, telefono;
    SQLiteDatabase sqld;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_4);

        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jet = (EditText) findViewById(R.id.xet);
        jsp = (Spinner) findViewById(R.id.xsp);

        if(ActivityCompat.checkSelfPermission(Activity4.this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED&&
                ActivityCompat.checkSelfPermission(Activity4.this,Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED){
            ActivityCompat.requestPermissions(Activity4.this, new String[]{
                    Manifest.permission.SEND_SMS,},1000);
        }

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBmsg", null, 1);
        sqld = dsqlh.getWritableDatabase();

        Cursor c = sqld.rawQuery("SELECT nombre FROM msg", null);
        ArrayList<String> orray = new ArrayList<String>();

        if (c.moveToFirst()) {
            do {
                orray.add(c.getString(0));
            } while (c.moveToNext());
        }
        ArrayAdapter<String> adapter = new ArrayAdapter(this, android.R.layout.simple_spinner_item, orray);
        jsp.setAdapter(adapter);

        jsp.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                nombre = jsp.getSelectedItem().toString();
            }

            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        jbn1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                String[] args = new String[] {nombre};
                Cursor c = sqld.rawQuery("SELECT telefono FROM msg WHERE nombre=?", args);
                if (c.moveToFirst()) {
                    do {
                        telefono = c.getString(0);
                    } while (c.moveToNext());
                }

                enviarMensaje(telefono,jet.getText().toString());

            }
        });

        jbn2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                Intent itn = new Intent(Activity4.this, Activity3.class);
                startActivity(itn);
            }
        });
    }

    private void enviarMensaje (String n, String m){
        try {
            SmsManager sms = SmsManager.getDefault();
            sms.sendTextMessage(n,null, m,null,null);
            Toast.makeText(getApplicationContext(), "Mensaje Enviado.",
                    Toast.LENGTH_LONG).show();
        }
        catch (Exception e) {
            Toast.makeText(getApplicationContext(), "Mensaje no enviado, datos incorrectos.", Toast.LENGTH_LONG).show();
            e.printStackTrace();
        }

    }
}