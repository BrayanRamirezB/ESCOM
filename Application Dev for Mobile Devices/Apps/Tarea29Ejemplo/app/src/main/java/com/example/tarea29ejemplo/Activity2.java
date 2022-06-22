package com.example.tarea29ejemplo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class Activity2 extends AppCompatActivity {
    EditText jet1, jet2;
    Button jbn;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);

        jet1 = (EditText)findViewById(R.id.xet1);
        jet2 = (EditText) findViewById(R.id.xet2);
        jbn = (Button)findViewById(R.id.xbn);

        if(ActivityCompat.checkSelfPermission(Activity2.this, Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED&&
                ActivityCompat.checkSelfPermission(Activity2.this,Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED){
            ActivityCompat.requestPermissions(Activity2.this, new String[]{
                    Manifest.permission.SEND_SMS,},1000);
        }
        jbn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                enviarMensaje(jet1.getText().toString(),jet2.getText().toString());
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