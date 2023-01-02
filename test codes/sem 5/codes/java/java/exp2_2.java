import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set; 

public class exp2_2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String,ArrayList<Integer>> hp = new HashMap<>();
		int num=0;
		int ct = 0;
		int size1 = 0;
		while(num>=0)
		{
			String key1;
			int val;
			System.out.println("Enter card :");
			key1 = sc.next();
			val = sc.nextInt();
			if(hp.containsKey(key1))
			{
				hp.get(key1).add(val);
			}
			else
			{
				hp.put(key1,new ArrayList<Integer>());
				hp.get(key1).add(val);
				size1++;
				
			}
			ct++;
			if(size1 >= 4)
				break;
		}
		System.out.println("Four symbols gathered in "+ ct +" cards.");
		System.out.println("Cards in Set are:");
		Set<String> keys = hp.keySet();
		ArrayList<Integer> l = new ArrayList<Integer>();
        for ( String key : keys ) {
        	l = hp.get(key);
            System.out.print( key + " " + l.get(0)+"\n");
        }
        
        sc.close();
        
	}

}

