/**
 * This is an implementation of the character pointer
 * in Java. We will use the abstract class defined in
 * CPointer.java.
 */

public class CCharPointer extends CPointer
{
    private int size;

    public CCharPointer() { super(1); size = 1; }
    public CCharPointer(int size) { super(size); this.size = size; }

    public int getSize() { return size; }

    public byte[] javaToCPointer(Object o) {
            String s = (String) o;
            byte[] toReturn = s.getBytes();

            return toReturn;
    }

    public static void main (String[] args) {
        CCharPointer s  = new CCharPointer();
        String jString  = new String("I'm a string.");
        byte[] myString = s.javaToCPointer(jString);
        s.setBytes(myString);

        int length1 = 0, length2 = jString.length();
       //simple string length calculation
        for (int x = 0; s.get(length1) != 0; length1++, s.PlusPlus()) {}
        System.out.printf("Java says string has length %d.\nMy pointer arithmetic says that the string is of length %d.\n", length2, length1);
    }
}
