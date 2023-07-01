import java.util.Scanner;

class Codechef {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt(); 
        scanner.nextLine();
        
        while (t-- > 0) {
            String[] input = scanner.nextLine().split(" ");
            String s = input[0]; // Input string
            int k = Integer.parseInt(input[1]); // Target sum
            
            if (hasSubsequenceWithHashSum(s, k)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        
        scanner.close();
    }
    
    private static boolean hasSubsequenceWithHashSum(String s, int k) {
        int n = s.length();
        
        // Iterate through each character in the string
        for (int i = 0; i < n; i++) {
            // Iterate through each character after the current character
            for (int j = i + 1; j < n; j++) {
                // Iterate through each character after the second character
                for (int m = j + 1; m < n; m++) {
                    int sum = getHash(s.charAt(i)) + getHash(s.charAt(j)) + getHash(s.charAt(m));
                    if (sum == k) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    private static int getHash(char c) {
        return c - 'a' + 1;
    }
}
