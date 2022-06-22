package com.example.pestaas2;

import android.os.*;
import android.view.*;
import androidx.fragment.app.Fragment;

public class Tab2 extends Fragment {
    @Override
    public void onCreate(Bundle b) {
        super.onCreate(b);
    }
    @Override
    public View onCreateView(LayoutInflater li, ViewGroup vg, Bundle bn) {
        return li.inflate(R.layout.tab2, vg, false);
    }
}
