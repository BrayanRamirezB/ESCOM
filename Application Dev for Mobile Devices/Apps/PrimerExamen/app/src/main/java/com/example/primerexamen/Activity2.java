package com.example.primerexamen;

import androidx.annotation.NonNull;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.widget.Button;
import com.itsxtt.patternlock.PatternLockView;
import java.util.ArrayList;
import io.paperdb.Paper;

public class Activity2 extends Activity {
    PatternLockView p;
    String patron = "", idpatron = "pattern_code";
    Intent itn;

    private String obtenerPatron(ArrayList<Integer> ids){
        String s = "";

        for (Integer id: ids)
            s += ids.toString();

        return s;
    }

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Paper.init(this);
        final String pattern = Paper.book().read(idpatron);

        if (patron != null && !patron.equals("null")) {
            setContentView(R.layout.activity_2);
            p = (PatternLockView) findViewById(R.id.xpl);

            p.setOnPatternListener(new PatternLockView.OnPatternListener() {
                public void onStarted() {}
                public void onProgress(@NonNull ArrayList<Integer> arrayList) { }

                public boolean onComplete(@NonNull ArrayList<Integer> arrayList) {
                    if (TextUtils.equals(pattern, obtenerPatron(arrayList))) {
                        itn = new Intent(Activity2.this, Activity3.class);
                        startActivity(itn);
                        return true;
                    } else {
                        return false;
                    }
                }
            });
        }
    }
}