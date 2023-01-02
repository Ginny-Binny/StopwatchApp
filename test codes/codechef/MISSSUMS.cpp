#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,i,j=0;
        cin>>n;
       
        for(i=1;i<100000;i++){
            if(i%2!=0){
                n=n-1;
                cout<<i<<" ";
                if(n<=0)
                break;

            }
        }
        cout<<endl;
    }
return 0;
}