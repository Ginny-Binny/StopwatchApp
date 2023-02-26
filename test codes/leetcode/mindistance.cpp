#include <vector>
#include <algorithm>

using namespace std;
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    
    // Create a 2D array of size (m+1) x (n+1)
    int dp[m+1][n+1];
    
    // Fill up the base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    
    // Fill up the rest of the array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }
    
    return dp[m][n];
}
