#include <bits/stdc++.h>
using namespace std;

// question one
int divide(int x,int y){
    string s="Can not divide by 0";
    if (y ==0){
        throw s;
    }
    else{
        return x/y;
    } 
}
int main(){
    int a, b, c;
    cout<<"Enter the value of 2 numbers"<<endl;
    cin>>a>>b;
    try{
        c=divide(a,b);
        cout<<c;
    }
    catch(string m){
        cout<<m;
    }
return 0;
}
