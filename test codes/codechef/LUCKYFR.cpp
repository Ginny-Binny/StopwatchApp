#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num, count=0,l;
        cin>>num;
        while(num>0){
        l=num%10;
        num=num/10;
        if(l==4){
            count++;
            
            }
        }
        
        cout<<count<<endl;
    } 
return 0;
}