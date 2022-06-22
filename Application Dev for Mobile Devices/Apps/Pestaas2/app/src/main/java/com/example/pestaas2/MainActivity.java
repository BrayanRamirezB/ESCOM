package com.example.pestaas2;

import android.os.Bundle;
import androidx.fragment.app.FragmentActivity;
import androidx.fragment.app.FragmentTabHost;

public class MainActivity extends FragmentActivity {
    private FragmentTabHost tabHost;
    protected void onCreate(Bundle b) {
        super.onCreate(b);
        setContentView(R.layout.activity_main);
        tabHost= (FragmentTabHost) findViewById(android.R.id.tabhost);
        tabHost.setup(this, getSupportFragmentManager(),android.R.id.tabcontent);
        tabHost.addTab(tabHost.newTabSpec("tab1").setIndicator("Pestaña 1"), Tab1.class,null);
        tabHost.addTab(tabHost.newTabSpec("tab2").setIndicator("Pestaña 2"), Tab2.class,null);
        tabHost.addTab(tabHost.newTabSpec("tab3").setIndicator("Pestaña 3"), Tab3.class,null);
        tabHost.addTab(tabHost.newTabSpec("tab4").setIndicator("Pestaña 4"), Tab4.class,null);
    }
}
