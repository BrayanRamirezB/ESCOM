package com.example.hilos2;

import android.app.*;
import android.os.*;
import android.widget.*;

public class MainActivity extends Activity {
    Handler h = new Control();
    TextView jtv1;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jtv1=(TextView) findViewById(R.id.xtv1);
        Hilo h1 = new Hilo(10, 1000); // 1seg = 1000ms
        Hilo h2 = new Hilo( 5, 500);
        //h2.setPriority(7);
        h1.setName("Id: "+ h1.getId() +" Hilo 1");
        h2.setName("Id: "+ h2.getId() +" Hilo 2");
        h1.start();
        h2.start();
    }
    class Hilo extends Thread{
        int n, t;
        Message m;
        Bundle b;

        Hilo(int n, int t){
            this.n = n;
            this.t = t;
        }

        public void run(){
            for(int i=0; i<n; i++){
                try{
                    Thread.sleep(t);
                }catch(InterruptedException ie){}
                m = h.obtainMessage();
                b = new Bundle();
                b.putInt("cuenta", i); //cuenta=i
                b.putString("hilo", currentThread().getName().toString());//hilo=currentThread()
                m.setData(b);
                h.sendMessage(m);
            }
        }
    }

    class Control extends Handler{
        public void handleMessage(Message m){
            int n;
            String s;
            n = m.getData().getInt("cuenta"); //cuenta=i
            s = m.getData().getString("hilo"); //hilo=currentThread()
            jtv1.append("\n" + n + " " + s);
        }
    }
}

