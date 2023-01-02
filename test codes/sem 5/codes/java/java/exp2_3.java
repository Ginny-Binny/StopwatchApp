import java.util.*;
public class exp2_3 {
	public static void main(String[] args)
	{
		 LinkedList<String> ll = new LinkedList<String>();
		 
		 Scanner sc = new Scanner(System.in);
		 System.out.println("CRUD OPERATIONS");

		 int exit = 1;
		 menu: do {
			 System.out.println("1.Insert");
			 System.out.println("2.Search");
			 System.out.println("3.Delete");
			 System.out.println("4.Display");
			 System.out.println("5.Exit");
			 System.out.println("Enter your choice");
			 int choice;
			 choice = sc.nextInt();
			 switch(choice) 
			 {
			 case 1:
				 System.out.println("Enter the String to be inserted:");
				 String s;
				 s = sc.next(); 
				 ll.add(s);
				 continue menu;
			 case 2:
				 System.out.println("Enter the String to be searched:");
				 String s1;
				 s1 = sc.next();
				 if(ll.contains(s1))
				 {
					 int index = ll.indexOf(s1);
					 System.out.println(s1+" is present at index: "+index);
				 }
				 else
					 System.out.println(s1+" is not present in the list");
			
				 continue menu;
			 case 3:
				 System.out.println("Enter the String to be deleted:");
				 String s2;
				 s2 = sc.next();
				 if(ll.contains(s2))
					 ll.remove(s2);
				 else
					 System.out.println(s2+" string is not avialable to be deleted");
				 continue menu;
			 case 4:
				 for(int p=0; p < ll.size(); p++)
				   {
				      System.out.println("Element at index "+p+": "+ll.get(p));
				    }
				 continue menu;
			 case 5:
				 exit = 0;
				 System.out.println("Thank You!!");
				 break menu;
			default:
				System.out.println("Invalid input");
			 }
		 }
		 while(exit !=0);
	}
}
 

