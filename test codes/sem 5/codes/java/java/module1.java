
import java.util.*;
class module1
{
	public static void main(String... args)
	{
		int empno[]={1001,1002,1003,1004,1005,1006,1007};
		String empname[]={"Ashish","Sushma","Rahul","Chahat","Ranjan","Suman","Tanmay"};
		String designationcode[]={"e","c","k","r","m","e","c"};
		String department[]={"R&D","PM","Acct","Front Desk","Engg","Manufacturing","PM"};
		int basic[]={20000,30000,10000,12000,50000,23000,29000};
		int hra[]={8000,12000,8000,6000,20000,9000,12000};
		int it[]={3000,9000,1000,2000,20000,4400,10000};
		
		String designationcodemean[]={"e","c","k","r","m"};
		String designation[]={"Engineer","Consultant","Clerk","Receptionist","Manager"};
		int da[]={20000,32000,12000,15000,40000};
		
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter employee number : ");
		int empnumber=sc.nextInt();
		
		
		String designationofemployee[];
		designationofemployee=new String[7];
		int da_sal[];
		da_sal=new int[7];
		int salary[];
		salary=new int[7];
		
		for(int a=0;a<7;a++)
		{
			if(designationcode[a]=="e")
			{
				designationofemployee[a]="Engineer";
				da_sal[a]=20000;
			}
			else if(designationcode[a]=="c")
			{
				designationofemployee[a]="Consultant";
				da_sal[a]=32000;
			}
			else if(designationcode[a]=="k")
			{
				designationofemployee[a]="Clerk";
				da_sal[a]=12000;
			}
			else if(designationcode[a]=="r")
			{
				designationofemployee[a]="Receptionist";
				da_sal[a]=15000;
			}
			else if(designationcode[a]=="m")
			{
				designationofemployee[a]="Manager";
				da_sal[a]=40000;
			}
		}
		
		
		for(int b=0;b<7;b++)
		{
			salary[b] = basic[b] + hra[b] + da_sal[b] - it[b];
		}
		
		for(int i=0;i<=7;i++)
		{
			if(i==7)
			{
				System.out.println("there is no employee with empid: "+empnumber);
				break;
			}
			else if(empno[i]==empnumber)
			{
				System.out.print(empno[i]+"  "+empname[i]+"  "+department[i]+"  "+designationofemployee[i]+"  "+salary[i]);
				break;
			}
			
		}
	}
}
		