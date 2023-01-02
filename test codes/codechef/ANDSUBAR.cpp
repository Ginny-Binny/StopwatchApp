#include <bits/stdc++.h>
using namespace std;

int setbits(int p){
    int ans = 0;
    while (p > 0){
        ans++;
        p = p >> 1;
    }
    return ans;
}

int main() {
    // your code goes here
    int array;
    cin >> array;
    
    while (array--){
        int N;
        cin >> N;
        
        int n = setbits(N);
        int ans1 = N - pow(2, n - 1) + 1;
        int ans2 = pow(2, n - 1) - pow(2, n - 2);
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}