package com.example.audiovideoejercicio1;

import android.os.Bundle;
import android.app.Activity;
import android.media.MediaPlayer;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity implements View.OnClickListener {
    MediaPlayer mp;
    Button jbn1, jbn2, jbn3, jbn4, jbn5;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn3 = (Button) findViewById(R.id.xbn3);
        jbn4 = (Button) findViewById(R.id.xbn4);
        jbn5 = (Button) findViewById(R.id.xbn5);
        jbn1.setOnClickListener(this);
        jbn2.setOnClickListener(this);
        jbn3.setOnClickListener(this);
        jbn4.setOnClickListener(this);
        jbn5.setOnClickListener(this);
    }

    public void onClick(View v) {
        if (v.getId() == R.id.xbn1) {
            reproducir(R.raw.c1);
        }
        if (v.getId() == R.id.xbn2) {
            reproducir(R.raw.c2);
        }
        if (v.getId() == R.id.xbn3) {
            reproducir(R.raw.c3);
        }
        if (v.getId() == R.id.xbn4) {
            reproducir(R.raw.c4);
        }
        if (v.getId() == R.id.xbn5) {
            reproducir(R.raw.c5);
        }
    }

    void reproducir(int cancion){
        if(mp != null) mp.release();
        mp = MediaPlayer.create(this, cancion);
        mp.seekTo(0);
        mp.start();
    }

    public void onPause(){
        super.onPause();
        if(mp != null)
            mp.release();
    }
}

