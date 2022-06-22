package com.example.tarea19ejemplo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.webkit.*;
import android.widget.*;

public class MainActivity extends Activity implements OnClickListener {
    Button jbn1, jbn2, jbn3, jbn4, jbn5;
    WebSettings ws;
    WebView wv;
    EditText jet;
    String s = "https://www.google.com/";
    String historial = "";
    Intent itn;
    Bundle bdl;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jbn1 = (Button) findViewById(R.id.xbn1);
        jbn1.setOnClickListener(this);
        jbn2 = (Button) findViewById(R.id.xbn2);
        jbn2.setOnClickListener(this);
        jbn3 = (Button) findViewById(R.id.xbn3);
        jbn3.setOnClickListener(this);
        jbn4 = (Button) findViewById(R.id.xbn4);
        jbn4.setOnClickListener(this);
        jbn5 = (Button) findViewById(R.id.xbn5);
        jbn5.setOnClickListener(this);
        jet = (EditText) findViewById(R.id.xet);
        wv = (WebView) findViewById(R.id.xwv);
        wv.setWebViewClient(new Cliente());
        ws = wv.getSettings();
        ws.setBuiltInZoomControls(true);
        ws.setJavaScriptEnabled(true);
        ws.setUseWideViewPort(true);

        jbn5.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                historial = historial + "\n" + jet.getText().toString();
                itn = new Intent(MainActivity.this, HistorialActivity.class);
                bdl = new Bundle();
                bdl.putString("Historial", historial);
                itn.putExtras(bdl);
                startActivity(itn);
            }
        });
    }

    class Cliente extends WebViewClient {
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            return false;
        }

        public void onPageFinished(WebView view, String url) {
            jet.setText(url);
            historial = historial + "\n" + jet.getText().toString();
        }
    }

    public void onClick(View v) {
        int id = v.getId();
        switch (id) {
            case R.id.xbn1:
                wv.goBack();
                historial = historial + "\n" + jet.getText().toString();
                break;
            case R.id.xbn2:
                wv.loadUrl(s);
                historial = historial + "\n" + s;
                break;
            case R.id.xbn3:
                wv.goForward();
                historial = historial + "\n" + jet.getText().toString();
                break;
            case R.id.xbn4:
                wv.loadUrl(jet.getText() + "");
                historial = historial + "\n" + jet.getText().toString();
                break;
        }
    }
}
