package com.example.cronometro;

import android.app.*;
import android.os.*;
import android.view.*;
import android.view.View.OnClickListener;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener{
    Chronometer c;
    Button jbnI, jbnF, jbnP, jbnC;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        c = (Chronometer)findViewById(R.id.xch);
        jbnI = (Button)findViewById(R.id.xbnI);
        jbnI.setOnClickListener(this);
        jbnF = (Button)findViewById(R.id.xbnF);
        jbnF.setOnClickListener(this);
        jbnP = (Button)findViewById(R.id.xbnP);
        jbnP.setOnClickListener(this);
        jbnC = (Button)findViewById(R.id.xbnC);
        jbnC.setOnClickListener(this);
    }

    public void onClick(View v){
        switch(v.getId()){
            case R.id.xbnI:
                c.setBase(SystemClock.elapsedRealtime());
                c.start();
                break;
            case R.id.xbnF:
                c.stop();
                break;
            case R.id.xbnP:
                c.stop();
                break;
            case R.id.xbnC:
                c.start();
                break;
        }
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        //getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
}