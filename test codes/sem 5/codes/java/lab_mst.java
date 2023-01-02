import java.util.Scanner;

public class lab_mst {

    public static void main(String... args)
	{//table1
		int Id[]={1,2,3,4};
		String PName[]={"Maggi", "Pasta", "Butter", "Soap"};
		int Price[]={10,24,52,36};
		int GSTCode[]={1,2,1,3};
    //table2
        int GSTCodemean[]={1,2,3};
		int GSTPercent[]={18,12,16};
		
        Scanner sc=new Scanner(System.in);
		System.out.println("Enter Product number : ");
		int productId=sc.nextInt();

		int GSTofProducString[];
		GSTofProducString=new int[3];
		
        for(int a=0;a<4;a++)
		{
			if(GSTCode[a]==1)
			{
				GSTCode[a]=1;
				Price[a]=Price[a] * 1.18;
			}
			else if(GSTCode[a]=="c")
			{
				GSTCode[a]="Consultant";
				da_sal[a]=32000;
			}
			else if(GSTCode[a]=="k")
			{
				GSTCode[a]="Clerk";
				da_sal[a]=12000;
			}
}
