package com.example.cuadromagico;

import android.os.Bundle;
import android.widget.TextView;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.widget.*;
import androidx.appcompat.app.AppCompatActivity;


public class CuadroMagico extends AppCompatActivity {
    TextView jtv;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cuadro_magico);

        Bundle datos = getIntent().getExtras();
        String dato = datos.getString("Dato");
        int n = Integer.parseInt(dato);
        int [][]magic = new int[n][n];

        recibirDato(n, magic);

        LinearLayout layout = (LinearLayout) findViewById(R.id.linearLayout1);
        TableLayout table = new TableLayout(this);

        for (int i = (n-1); i >= 0; i--) {
            TableRow row = new TableRow(this);
            for (int j = 0; j < n; j++) {
                TextView cell = new androidx.appcompat.widget.AppCompatTextView(this) {
                    protected void onDraw(Canvas canvas) {
                        super.onDraw(canvas);
                        Rect rect = new Rect();
                        Paint paint = new Paint();
                        paint.setStyle(Paint.Style.STROKE);
                        paint.setColor(Color.BLACK);
                        paint.setStrokeWidth(6);
                        getLocalVisibleRect(rect);
                        canvas.drawRect(rect, paint);
                    }
                };
                cell.setTextSize(25);
                cell.setText(String.valueOf(magic[i][j]));
                cell.setPadding(6, 4, 6, 4);
                row.addView(cell);
            }
            table.addView(row);
        }
        layout.addView(table);
    }

    private void recibirDato(int n, int magic[][]) {
        if (n % 2 == 0) throw new RuntimeException("n must be odd");

        int row = n - 1;
        int col = n / 2;
        magic[row][col] = 1;

        for (int i = 2; i <= n * n; i++) {
            if (magic[(row + 1) % n][(col + 1) % n] == 0) {
                row = (row + 1) % n;
                col = (col + 1) % n;
            } else {
                row = (row - 1 + n) % n;
            }
            magic[row][col] = i;
        }
    }
}