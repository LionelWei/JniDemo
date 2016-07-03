package android.example.com.jnidemo1;

/**
 * Created by Lionel on 2016/7/2.
 */
public class EgameProxyManager {
    static {
        System.loadLibrary("EgameProxy");
    }

    public native String getProxyIp();

    public native int getProxyPort();
}
