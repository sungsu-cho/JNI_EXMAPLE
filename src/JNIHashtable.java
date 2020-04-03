import java.util.Hashtable;
public class JNIHashtable {
    static {
        System.loadLibrary("JNIHashtable");
    }

    private native Hashtable getHashtable();

    public static void main(String[] args) {
        String key = "star";
        JNIHashtable jniHashT = new JNIHashtable();

        Hashtable h = jniHashT.getHashtable();
        String val = (String)h.get(key);
        System.out.println(key +" "+ val );
    }
}
