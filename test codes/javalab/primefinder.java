import java.util.*;

public class primefinder {

    public static int isprime(int n){
        int c=0;
        for(int i=2; i<n;i++){
            if(n%i==0){
                c++;
                break;

            }
        }

        if(c==0){
            return 0;

        }

        else{
            return 1;

        }
    }

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array:");
        n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0; i<n; i++){
            arr[i]=sc.nextInt();

        }

        for(int i=0; i<n;i++){
            if(isprime(arr[i])==0){
                System.out.print(arr[i]+" ");
            }
        }
        sc.close();
    }
    }
    

