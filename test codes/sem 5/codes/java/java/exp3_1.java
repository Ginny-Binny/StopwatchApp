import java.util.Scanner;

public class exp3_1 {
    static String longestPalSubstr(String str)
    {
        int n = str.length();
        if (n < 2)
            return "";
 
        int maxLength = 1,start=0;
        int low, high;
        for (int i = 0; i < n; i++) {
            low = i - 1;
            high = i + 1;
            while ( high < n && str.charAt(high) == str.charAt(i)) //increment 'high'                                  
                high++;
       
            while ( low >= 0 && str.charAt(low) == str.charAt(i)) // decrement 'low'                   
                low--;
       
            while (low >= 0 && high < n && str.charAt(low) == str.charAt(high) ){
                  low--;
                high++;
        }
 
        int length = high - low - 1;
        if (maxLength < length){
            maxLength = length;
            start=low+1;
        }
    }   
    return str.substring(start, start + maxLength );
       
 }
 
    public static void main(String[] args)
    {
 
    	
        String str;
        System.out.println("Enter the string:");
        Scanner sc = new Scanner(System.in);
        str = sc.next();
        System.out.print("Longest palindrome substring is: "+longestPalSubstr(str));
    }
}







