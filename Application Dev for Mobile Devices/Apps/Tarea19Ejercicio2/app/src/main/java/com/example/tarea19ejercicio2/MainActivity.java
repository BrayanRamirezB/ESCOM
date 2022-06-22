package com.example.tarea19ejercicio2;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.*;

public class MainActivity extends Activity {
    WebView wv;

    public void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        wv = (WebView) findViewById(R.id.xwv);
        wv.setWebViewClient(new WebViewClient());
        wv.getSettings().setJavaScriptEnabled(true);
        wv.loadUrl("file:///android_asset/webview1.html");

        wv.setWebViewClient(new WebViewClient() {
            public void onPageFinished(WebView view, String weburl) {
                wv.loadUrl("javascript:testEcho('Javascript function in webview')");
            }
        });
    }
}

