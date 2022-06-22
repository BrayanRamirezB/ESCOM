package com.example.sensores4;

import android.app.*;
import android.net.*;
import android.os.*;
import android.view.View;
import android.view.View.*;
import android.widget.*;

public class Activity2 extends Activity implements OnClickListener {
    Button jbn;
    VideoView vvw;
    Uri uri;
    MediaController mcr;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_2);
        jbn = (Button) findViewById(R.id.xbn);
        jbn.setOnClickListener(this);
    }

    public void onClick(View v) {
        vvw = (VideoView) findViewById(R.id.xvv1);
        uri = Uri.parse("android.resource://com.example.sensores4/" + R.raw.ace_of_spades);
        mcr = new MediaController(this);
        vvw.setMediaController(mcr);
        vvw.setVideoURI(uri);
        vvw.start();
    }
}