#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2!=0){
            cout<<-1<<'\n';
        }
        else{
            for(int i=0;i<n/2;i++){
                cout<<0;

            }
            for(int i=n/2;i<n;i++){
                cout<<1;

            }
            cout<<'\n';
        }
    } 
return 0;
}