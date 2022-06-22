package com.example.lienzo;

import android.content.*;
import android.graphics.*;
import android.view.View;

public class Lienzo extends View{
    Paint p;
    int x, y;

    public Lienzo(Context c){
        super(c);
    }
    protected void onDraw(Canvas c){
        super.onDraw(c); // Canvas pinta atributos
        p = new Paint(); // Paint asigna atributos
        x = c.getWidth(); // También: getMeasuredWidth() o getRight(), x=480
        y = c.getHeight(); // También: getMeasuredHeight() o getBottom(), y=762
        p.setColor(Color.WHITE); // Fondo blanco
        c.drawPaint(p);
        p.setColor(Color.BLACK); // Texto negro
        p.setTextSize(20);
        c.drawText("x0=" + x/2 + ", y0=" + y/2, x/2 + 20, y/2-20, p);
        p.setColor(Color.rgb(0, 0, 255)); // Ejes azules
        c.drawLine(x/2, 0, x/2, y, p);
        c.drawLine(0, y/2, x, y/2, p);
        p.setTextAlign(Paint.Align.RIGHT);
        p.setTypeface(Typeface.MONOSPACE);
        c.drawText("Eje X", x-5, y/2-10, p);
        p.setTextAlign(Paint.Align.CENTER);
        p.setTypeface(Typeface.MONOSPACE);
        c.drawText("Eje Y", x/2+30, 20, p);
        p.setColor(Color.argb(100, 200, 100, 100));
        //c.drawCircle(x/2-120, y/2+120, 100, p);
        c.drawOval(100,300,260,365,p);
        c.drawRect(500,343,580,348,p);
        c.drawRoundRect(100,1000,260,1070,190,190,p);
        c.drawArc(480,1000,620,1070,-180,180,false,p);
    }
}