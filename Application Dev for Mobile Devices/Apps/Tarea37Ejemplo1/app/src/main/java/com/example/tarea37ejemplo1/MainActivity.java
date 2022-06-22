package com.example.tarea37ejemplo1;

import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.content.Intent;
import android.util.Log;
import android.view.*;
import android.view.View.*;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener {

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        Button jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(this);
    }

    public void onClick(View v){
        enviarEmail();
    }

    protected void enviarEmail() {
        Log.i("Enviar email", "");
        String[] TO = {""};
        String[] CC = {""};
        Intent emailIntent = new Intent(Intent.ACTION_SEND);
        emailIntent.setData(Uri.parse("mailto:"));
        emailIntent.setType("text/plain");
        emailIntent.putExtra(Intent.EXTRA_EMAIL, TO);
        emailIntent.putExtra(Intent.EXTRA_CC, CC);
        emailIntent.putExtra(Intent.EXTRA_SUBJECT, "De ESCOM");
        emailIntent.putExtra(Intent.EXTRA_TEXT, "Correo desde Android Studio");
        try {
            startActivity(Intent.createChooser(emailIntent, "Send mail..."));
            finish();
            Log.i("Fin envío de correo...", ""); // Máximo 23 caracteres
        } catch (android.content.ActivityNotFoundException ex) {
            Toast.makeText(MainActivity.this, "No hay cliente de correo instalado.",
                    Toast.LENGTH_SHORT).show();
        }
    }
}