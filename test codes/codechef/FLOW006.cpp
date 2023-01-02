#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num, sum=0 , n;
        cin>>num;
        while(num>0){
        n=num%10;
        sum=sum+n;
        num=num/10;
        }
        cout<<sum<<endl;
    } 
return 0;
}