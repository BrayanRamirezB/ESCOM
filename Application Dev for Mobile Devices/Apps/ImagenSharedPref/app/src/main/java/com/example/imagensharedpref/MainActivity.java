package com.example.imagensharedpref;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.*;
import android.app.*;
import android.provider.MediaStore;
import android.view.View;
import android.widget.*;

public class MainActivity extends Activity {

    SharedPreferences sp;
    Button btn, seleccion;
    Intent intent;
    float x, y;
    Uri path;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        btn = (Button) findViewById(R.id.btn);
        seleccion = (Button) findViewById(R.id.selecion);
        sp = getSharedPreferences("preferencias", Context.MODE_PRIVATE);
        seleccion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                cargarImagen();
            }
        });

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SharedPreferences.Editor miEditor = sp.edit();
                miEditor.putString("path", path.toString());
                miEditor.commit();
                Toast.makeText(view.getContext(), "Preferencias guardadas", Toast.LENGTH_LONG).show();
                intent = new Intent(MainActivity.this, SecondActivity.class);
                startActivity(intent);
            }
        });

    }

    private void cargarImagen() {
        Intent intent = new Intent(Intent.ACTION_PICK, MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        intent.setType("image/");
        startActivityForResult(intent.createChooser(intent, "Seleccion la aplicacion"), 10);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == RESULT_OK) {
            path = data.getData();
            Toast.makeText(this, "Se ha seleccionado la imagen correctamente", Toast.LENGTH_LONG).show();
        }
    }
}