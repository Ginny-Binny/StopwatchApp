#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=2;i<=n;i++){
            if(m==0)
            break;
            cout<<i-1<<" "<<i<<"\n";
            m-=1;

        }
        ll low =1, high =n, c=-1;
        while(low<=high){
            ll mid=(low+high)/2;
            ll sum= (mid*(mid-1))/2;
            if(sum==(m+mid-1)){
                c=mid;
                break;

            }
            else if(sum<(m+mid-1))
            low=mid+1;
            else 
            high=mid-1;


        }
        if(c==-1)
            c=low;
            for(ll i=1;i<=c;i++){
                for(ll j=i+2;j<=c;j++){
                    if(m==0)
                    break;
                    cout<<i<<" "<<j<<"\n";
                    m--;

                }
                if(m==0)
                break;

            }
        }
    }


