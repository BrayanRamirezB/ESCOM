package com.example.botones;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.*;
import android.media.MediaPlayer;

public class MainActivity extends Activity {

    MediaPlayer mp;
    Button btn;
    public void onCreate(Bundle b){
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        btn = (Button) findViewById(R.id.btnSonido);
        btn.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                mp.start();
            }
        });
        mp = MediaPlayer.create(MainActivity.this, R.raw.sonido3);
        mp.start();
    }

    public void onDestroy(){
        mp.stop();
        super.onDestroy();
    }
}