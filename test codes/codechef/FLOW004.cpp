#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int num, l;
        cin>>num;
        l=num%10;
        while(num>=10){
            num=num/10;
        }
        cout<<num+l<<endl;
          }
return 0;
}