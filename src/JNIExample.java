public class JNIExample {
    private final int[] data = new int[]{5, 4, 3, 2, 1};

    public native int sum(int a, int b);
    public native void quickSort();

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (int i : data) {
            str.append(i).append(" ");
        }
        str.trimToSize();
        return str.toString();
    }

    static {
        System.loadLibrary("JNIExample");
    }

    public static void main(String[] args) {
        JNIExample JNIExample = new JNIExample();
        JNIExample.quickSort();
        System.out.println(JNIExample.sum(3, 7));
        System.out.println(JNIExample);

    }
}