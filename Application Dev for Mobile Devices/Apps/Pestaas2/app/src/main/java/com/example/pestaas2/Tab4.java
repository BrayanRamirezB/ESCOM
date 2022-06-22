package com.example.pestaas2;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.*;
import android.view.*;
import android.widget.RelativeLayout;
import androidx.fragment.app.Fragment;

public class Tab4 extends Fragment{

    public void onCreate(Bundle b) {
        super.onCreate(b);
    }

    private class Dibujo extends View{
        Paint p = new Paint();

        public Dibujo(Context context) {
            super(context);
        }

        public void onDraw(Canvas c) {
            super.onDraw(c);

            for(int i = 10; i > 0; i--){
                p.setColor(Color.RED);
                c.drawRect(340 - (i*20),620 - (i*20),380 + (i*20),660 + (i*20),p);
                p.setColor(Color.WHITE);
                c.drawCircle(360,640,20  + (i*20), p);
            }



        }
    }

    public View onCreateView(LayoutInflater li, ViewGroup vg, Bundle bn)  {
        View rootView = li.inflate(R.layout.tab4, vg,false);
        RelativeLayout rl = (RelativeLayout) rootView.findViewById(R.id.fr);
        rl.addView(new Dibujo(getActivity()));
        return rootView;
    }
}


/*
            for(i = 0; i<10 ; i++){
            p.setColor(Color.RED);
            c.drawRect(0,300,700,980,p);
            p.setColor(Color.WHITE);
            c.drawCircle(360,640,340,p);

            p.setColor(Color.RED);
            c.drawRect(100,400,600,880,p);
            p.setColor(Color.WHITE);
            c.drawCircle(360,640,240,p);

            p.setColor(Color.RED);
            c.drawRect(160,480,550,780,p);
            p.setColor(Color.WHITE);
            c.drawCircle(360,640,150,p);
            }

            p.setColor(Color.RED);
                c.drawRect(340 - (i*20),620 - (i*20),380 + (i*20),660 + (i*20),p);
                p.setColor(Color.WHITE);
                c.drawCircle(360,640,20, p);
            */


