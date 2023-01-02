import java.util.*;

public class abcd

{

    /**
     * @param args
     */
    public static void main(String[] args)

    {

        abcd<Integer> lhashSet = new abcd<Integer>();

        lhashSet.add(new Integer(1));

        lhashSet.add(new Integer(2));

        lhashSet.add(new Integer(3));

        lhashSet.add(new Integer(3));

        lhashSet.add(new Integer(5));

        lhashSet.add(new Integer(4));

        lhashSet.add(new Integer(5));

        lhashSet.add(new Integer(5));

        Object[] objArray = lhashSet.toArray();

        for (Object element : objArray)

            System.out.print(element + " ");

    }

}
