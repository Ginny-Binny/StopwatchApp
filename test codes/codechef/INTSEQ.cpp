#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int ans=0;
        while(n>1){
            if(n%2){
                break;

            }
            ans++;
            n/=2;
        }
        cout<<ans<<endl;
    } 
return 0;
}