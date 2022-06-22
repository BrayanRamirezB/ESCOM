package com.example.audiovideo;

import android.net.Uri;
import android.os.Bundle;
import android.app.Activity;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.VideoView;
import android.widget.*;

public class Second extends Activity {
    Bundle bdl;
    String res;
    MediaPlayer mp;
    Button jbn;
    VideoView vvw;
    Uri uri;
    MediaController mcr;
    TextView jtv;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        bdl = getIntent().getExtras();
        res = bdl.getString("ID");
        jbn = (Button) findViewById(R.id.btnRepro);
        jtv = (TextView) findViewById(R.id.xtv);

        if (res.equals("c1")) {
            reproducir(R.raw.c1);
            jtv.setText("Reproduciendo: Metallingus - Alter Bridge");
        }
        if (res.equals("c2")) {
            reproducir(R.raw.c2);
            jtv.setText("Reproduciendo: Dead Memories - Slipknot");
        }
        if (res.equals("c3")) {
            reproducir(R.raw.c3);
            jtv.setText("Reproduciendo: Freak on a lesh - Korn");
        }
        if (res.equals("c4")) {
            reproducir(R.raw.c4);
            jtv.setText("Reproduciendo: The game - Motorhead");
        }
        if (res.equals("this_is_love")) {
            vvw = (VideoView) findViewById(R.id.video);
            vvw.setVisibility(View.VISIBLE);
            jbn.setVisibility(View.VISIBLE);
            uri = Uri.parse("android.resource://com.example.audiovideo/" + R.raw.this_is_love);
            mcr = new MediaController(this);
            vvw.setMediaController(mcr);
            vvw.setVideoURI(uri);
            vvw.start();
        }
        if (res.equals("this_is_love")) {
            jbn.setVisibility(View.VISIBLE);
            vvw = (VideoView) findViewById(R.id.video);
            vvw.setVisibility(View.VISIBLE);
            uri = Uri.parse("android.resource://com.example.audiovideo/" + R.raw.this_is_love);
            mcr = new MediaController(this);
            vvw.setMediaController(mcr);
            vvw.setVideoURI(uri);
            vvw.start();

        }
    }

    void reproducir(int cancion) {
        if (mp != null) mp.release();
        mp = MediaPlayer.create(this, cancion);
        mp.seekTo(0);
        mp.start();
    }

    public void onPause() {
        super.onPause();
        if (mp != null) mp.release();
    }
}