package android.example.com.jnidemo1;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView = (TextView) findViewById(R.id.text1);

        EgameProxyManager manager = new EgameProxyManager();
        String ip = manager.getProxyIp();
//        int port = manager.getProxyPort();
        int port = 80;

        textView.setText("ip: " + ip + ", port:" + port);
    }
}
