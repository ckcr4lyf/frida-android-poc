package com.example.fridapoc;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.fridapoc.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'fridapoc' library on application startup.
    static {
        System.loadLibrary("fridapoc");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;

        ExampleAlpha myInstance = new ExampleAlpha();
        int myInt = intFromJNIViaClass(myInstance);
//        tv.setText(stringFromJNI());
        tv.setText(Integer.toString(myInt));
    }


    /**
     * A native method that is implemented by the 'fridapoc' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native int intFromJNIViaClass(ExampleAlpha instance);
}