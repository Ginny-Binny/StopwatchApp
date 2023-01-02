#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        if( (a-1)%4==0 || (a-1)==0)
        cout<<"East"<<endl;
        else if( (a+2)%4==0)
        cout<<"South"<<endl;
        else if((a+1)%4==0)
        cout<<"West"<<endl;
        else
        cout<<"North"<<endl;

    } 
return 0;
}