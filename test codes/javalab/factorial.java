import java.util.Scanner;

public class factorial {
    public static void main(String [] args){

        int fact =1;
        int i =1;

        Scanner sc= new Scanner(System.in);

        System.out.println("Enter the number to calculate its factorial ");
        int num = sc.nextInt();

        while(i<=num){
            fact=fact*i;
            i++;

        }

        System.out.println("\n Factorial of " +num+" is: " +fact);
        sc.close();

    }
}
