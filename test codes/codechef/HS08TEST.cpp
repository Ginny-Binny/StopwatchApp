#include <bits/stdc++.h>
using namespace std;
int main(){
   int a;
   float b;
    cin>>a>>b;
    if(a%5==0 && b>=(a+.5)){
        b-=(a+.5);
    }
    cout<<fixed<<setprecision(2)<<b;
    
return 0;
}