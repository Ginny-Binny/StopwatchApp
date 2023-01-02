#include <bits/stdc++.h>
using namespace std;
int factorial(int num);
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,fact=1;
        cin>>num;
        while(num>=1){

            fact=fact*num;
            num--;


        }
    cout<<fact<<endl;
    }}