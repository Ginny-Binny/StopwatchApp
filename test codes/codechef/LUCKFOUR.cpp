#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        int count=0;
        while(num>0){
            if(num%10==4){
                count++;
            }
            num=num/10;
            

        }cout<<count<<endl;
    } 
}