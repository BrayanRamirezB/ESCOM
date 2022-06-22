package com.example.primerexamen;


import android.app.Activity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import com.itsxtt.patternlock.*;
import java.util.ArrayList;
import io.paperdb.Paper;
import android.content.Intent;
import androidx.annotation.NonNull;

public class MainActivity extends Activity {
    PatternLockView p;
    String patron = "", idpatron = "pattern_code";
    Button jbn;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Paper.init(this);
        final String pattern = Paper.book().read(idpatron);
        jbn = (Button) findViewById(R.id.xbn);

        if(pattern != null && !pattern.equals("null")  ){
            setContentView(R.layout.activity_2);
            p = (PatternLockView) findViewById(R.id.xpl);
            p.setOnPatternListener(new PatternLockView.OnPatternListener() {
                public void onStarted() {}
                public void onProgress(@NonNull ArrayList<Integer> arrayList) {}

                public boolean onComplete(@NonNull ArrayList<Integer> arrayList) {
                    if (TextUtils.equals(pattern, obtenerPatron(arrayList))){
                        Intent itn = new Intent(MainActivity.this, Activity3.class);
                        startActivity(itn);
                        return true;
                    } else{
                        return false;
                    }
                }
            });

            jbn.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    Paper.book().destroy();
                    Intent itn = new Intent(MainActivity.this, MainActivity.class);
                    startActivity(itn);
                }
            });
        } else {
            setContentView(R.layout.activity_main);
            p = (PatternLockView) findViewById(R.id.xpl);
            p.setOnPatternListener(new PatternLockView.OnPatternListener() {
                public void onStarted() {}
                public void onProgress(@NonNull ArrayList<Integer> arrayList) {}

                public boolean onComplete(@NonNull ArrayList<Integer> arrayList) {
                    patron = obtenerPatron(arrayList);
                    return true;
                }
            });

            jbn.setOnClickListener(new View.OnClickListener() {
                public void onClick(View view) {
                    Paper.book().write(idpatron, patron);
                    Intent itn = new Intent(MainActivity.this, Activity2.class);
                    startActivity(itn);
                }
            });
        }
    }

    private String obtenerPatron(ArrayList<Integer> ids){
        String s = "";

        for (Integer id: ids)
            s += ids.toString();

        return s;
    }
}