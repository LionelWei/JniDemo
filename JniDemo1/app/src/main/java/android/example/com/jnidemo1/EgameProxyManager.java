package android.example.com.jnidemo1;

import android.util.Log;

/**
 * Created by Lionel on 2016/7/2.
 */
public class EgameProxyManager {
    static {
        System.loadLibrary("EgameProxy");
    }

    public int myport = 8888;

    public native String getProxyIp();

    public native int getProxyPort();

    public void haha() {
        Log.d("PORT", ""+myport);
    }
}
