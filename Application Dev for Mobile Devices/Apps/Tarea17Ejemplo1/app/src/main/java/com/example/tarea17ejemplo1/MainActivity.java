package com.example.tarea17ejemplo1;

import android.app.*;
import android.content.ContentValues;
import android.database.sqlite.SQLiteDatabase;
import android.os.*;
import android.view.*;
import android.view.View.OnClickListener;
import android.widget.*;
import java.util.*;

public class MainActivity extends Activity implements OnClickListener {
    Button jbnF, jbnH, jbnG;
    EditText txtDate, txtTime, txtNombre;
    int a, m, d, h, n;
    ImageView jimg;
    SQLiteDatabase sqld;

    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        jbnF = (Button)findViewById(R.id.xbnF);
        jbnF.setOnClickListener(this);
        jbnH = (Button)findViewById(R.id.xbnH);
        jbnH.setOnClickListener(this);
        jbnG = (Button) findViewById(R.id.xbnG);
        jimg = (ImageView) findViewById(R.id.ximg);
        txtDate = (EditText)findViewById(R.id.xetF);
        txtTime = (EditText)findViewById(R.id.xetH);
        txtNombre = (EditText) findViewById(R.id.xetN);

        DbmsSQLiteHelper dsqlh = new DbmsSQLiteHelper(this, "DBTarea17", null,1);
        sqld = dsqlh.getWritableDatabase();
        jbnG.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                String nombre = txtNombre.getText().toString();
                String fecha = txtDate.getText().toString();
                String hora = txtTime.getText().toString();
                ContentValues cv = new ContentValues();
                cv.put("Nombre",nombre);
                cv.put("Fecha",fecha);
                cv.put("Hora",hora);
                sqld.insert("Tarea17",null,cv);
                txtDate.setText("");
                txtNombre.setText("");
                txtTime.setText("");
                Toast.makeText(getBaseContext(),"Guardado en BD", Toast.LENGTH_SHORT).show();
            }
        });

        jimg.setImageResource(R.drawable.im1);
    }

    public void onClick(View v) {
        if (v == jbnF) {
            Calendar c = Calendar.getInstance();
            a = c.get(Calendar.YEAR);
            m = c.get(Calendar.MONTH);
            d = c.get(Calendar.DAY_OF_MONTH);
            DatePickerDialog dpd = new DatePickerDialog(this, new
                    DatePickerDialog.OnDateSetListener() {
                        public void onDateSet(DatePicker dp, int ye, int mo, int di) {
                            txtDate.setText(di + "-" + (mo + 1) + "-" + ye);
                        }
                    }, a, m, d);
            dpd.show();
        }
        if (v == jbnH) {
            Calendar c = Calendar.getInstance();
            h = c.get(Calendar.HOUR_OF_DAY);
            n = c.get(Calendar.MINUTE);
            TimePickerDialog tpd = new TimePickerDialog(this, new
                    TimePickerDialog.OnTimeSetListener() {
                        public void onTimeSet(TimePicker tp, int ho, int mi) {
                            txtTime.setText(ho + ":" + mi);
                        }
                    }, h, n, false);
            tpd.show();
        }
    }
}