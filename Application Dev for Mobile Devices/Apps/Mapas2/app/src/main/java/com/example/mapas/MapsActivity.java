package com.example.mapas;

import androidx.fragment.app.FragmentActivity;

import android.content.Context;
import android.graphics.Canvas;
import android.os.Bundle;
import android.view.View;
import android.view.View.*;
import android.widget.Button;
import android.widget.Toast;
import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapView;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.Projection;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {
    private GoogleMap mMap;
    private Button jbnsatelite = null;
    private Button jbncentrar = null;
    private Button jbnanimar = null;
    private Button jbnmover = null;
    private int s = 0;//Variable para cambiar la vista del mapa
    double latitud, longitud;

    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        jbnsatelite = (Button) findViewById(R.id.xbnsatelite);
        jbncentrar = (Button) findViewById(R.id.xbncentrar);
        jbnanimar = (Button) findViewById(R.id.xbnanimar);
        jbnmover = (Button) findViewById(R.id.xbnmover);

        // Obtain the SupportMapFragment and get notified when the map is ready to be used.
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);

        //Boton para cambiar la vista a satelite y viceversa.
        jbnsatelite.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                if(s == 0){
                    mMap.setMapType(mMap.MAP_TYPE_SATELLITE);
                    s = 1;
                }else{
                    mMap.setMapType(mMap.MAP_TYPE_NORMAL);
                    s = 0;
                }
            }
        });

        //Boton para centrar el mapa, tiene por defecto las coordenadas de sevilla
        jbncentrar.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                LatLng lugar = new LatLng(37.40, -5.99);
                CameraUpdate camUpd1 = CameraUpdateFactory.newLatLngZoom(new LatLng(37.40, -5.99), 10);
                mMap.addMarker(new MarkerOptions().position(lugar).title("Marker in Sevilla"));
                mMap.moveCamera(camUpd1);
                obtenerPosicion();
            }
        });

        //Boton para animar (Primero hacer click en  el boton centrar)
        jbnanimar.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                LatLng madrid = new LatLng(latitud, longitud);
                CameraPosition camPos = new CameraPosition.Builder().target(madrid) .zoom(10) .bearing(45).tilt(70).build();
                CameraUpdate camUpd3 = CameraUpdateFactory.newCameraPosition(camPos);
                mMap.animateCamera(camUpd3);
            }
        });

        //Boton para mover las coordenadas del mapa
        jbnmover.setOnClickListener(new OnClickListener() {
            public void onClick(View view) {
                LatLng lugar = new LatLng(19.504270, -99.146958);
                CameraUpdate camUpd1 = CameraUpdateFactory.newLatLngZoom(new LatLng(19.504270, -99.146958), 10);
                mMap.addMarker(new MarkerOptions().position(lugar).title("Marker in ESCOM"));
                mMap.moveCamera(camUpd1);
                Toast.makeText(MapsActivity.this, "Lat: " + 19.504270 + "\n" + "Lng: " + -99.146958 + "\n" , Toast.LENGTH_SHORT).show();
            }
        });
    }

    public void obtenerPosicion(){
        CameraPosition camPos = mMap.getCameraPosition();
        LatLng coordenadas = camPos.target;
        latitud = coordenadas.latitude;
        longitud = coordenadas.longitude;
        Toast.makeText(this, "Lat: " + latitud + " | Long: " + longitud,
                Toast.LENGTH_SHORT).show();
    }

    public void onMapReady (GoogleMap googleMap){
        mMap = googleMap;
        // Add a marker in Sydney and move the camera
        LatLng sydney = new LatLng(-34, 151);
        mMap.addMarker(new MarkerOptions().position(sydney).title("Marker in Sydney"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));
    }

}