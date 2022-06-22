package com.example.imagensharedpref;

import android.content.Context;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.widget.*;

public class SecondActivity extends Activity{

    ImageView img;
    SharedPreferences sp;
    Uri path;

    String x;

    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_second);
        img = (ImageView)findViewById(R.id.imagen);
        sp = getSharedPreferences("preferencias", Context.MODE_PRIVATE);
        x = sp.getString("path", "");
        path = Uri.parse(x);
        img.setImageURI(path);

    }
}