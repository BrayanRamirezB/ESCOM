package com.example.kotlinparte1

import android.os.Bundle
import android.app.Activity
import android.content.Context
import android.util.Log
import android.widget.Toast
import kotlinx.android.synthetic.main.*
import kotlinx.android.synthetic.main.activity_main.*

class SecondActivity: Activity () {
    override fun onCreate (savedInstanceState: Bundle?) {
        super.onCreate (savedInstanceState)
        setContentView(R.layout.activity_main)

        //Variable Null
        var a : String? = null

        //Operador ?
        Log.d("tag: ", ""+a?.length)

        //Expresion Lambda y funcion de extension
        boton.setOnClickListener {

            //Operador !!
            if(a!!.toString().equals("")){
                setColor(null)
            }else{
                setColor("verde")
            }
        }

        //Objeto Singleton
        kotlinSingleton.myFunction(this,"Objeto s", Toast.LENGTH_LONG)
    }

    //Operador ?:
    fun setColor(color:String?){
        var c = color?:"N/A"
        var a : String? = "El color es: " + c
    }

    //Objetos singleton
    object kotlinSingleton{
        fun myFunction(context: Context, msg:String, int: Int){
            Toast.makeText(context,msg,int).show()
        }
    }
}