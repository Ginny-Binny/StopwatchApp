#include <bits/stdc++.h>
using namespace std;

int modular_inverse(int x, int mod)
{
    for(int i=1;i<mod;i++)
        if(((x%mod)* (i%mod)) % mod ==1 )
        return i;
        
        }


int main(){

    int x=3;
    int mod=7;
    cout<<modular_inverse(x,mod);

     
return 0;
}