import java.util.*; 

public class exp2_1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Map<String,ArrayList<Integer>> hp = new HashMap<>();
		
		System.out.println("Enter the number of Cards:");
		int num;
		num = sc.nextInt();
		for(int i=0;i<num;i++)
		{
			String key1;
			int val;
			System.out.println("Enter card "+(i+1)+":");
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
			}
			
		}
		System.out.println("Distinct Symbols are:");
		Set<String> keys = hp.keySet();
        for ( String key : keys ) {
            System.out.print( key + " " );
        }
        
        for(String key : keys)
        {
        	System.out.println("\nCards in "+key+" Symbol");
        	System.out.println(key+" "+hp.get(key));
        	System.out.println("Number of cards:"+hp.get(key).size());
        	int sum = 0;
        	ArrayList<Integer> l = new ArrayList<Integer>();
        	l = hp.get(key);
        	for(int i:l)
        		sum = sum + i;
        	System.out.println("Sum of numbers:"+sum);
        	
        }
		
	}

}
