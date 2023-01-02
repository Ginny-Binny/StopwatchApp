#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num, rev, n;
        cin>>num;

        while(num!=0){
        n=num%10;
        rev=rev*10+n;
        n/=10;
            } 
    cout<<rev;
    }
return 0;
}