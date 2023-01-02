#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define show(v) for(int i=0; i<(int)v.size(); ++i) cout<<v[i]<<" "

const ll max_size = 1e5+5;
bool prime[max_size];

void prime_seive(ll n)
{
  memset(prime, true, sizeof(prime));
  for(ll i=2; i*i<=n; i++)
  {
    if(prime[i])
    {
      for(ll j=i*i; j<=n; j+=i)
      prime[j]=false;
    }
  }
}

void solve();
int main()
{
    prime_seive(max_size);
    ll t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

void solve()
{
    ll n,k; cin>>n>>k;
    
    if(k == 1 || n == 2) {
        cout<<"YES"<<endl;
        cout<<1<<endl; return ;
    }
    
    if(n == 3)
    {
        cout<<"YES"<<endl;
        cout<<1<<" "<<2<<endl;
        return;
    }
    
    vector<ll> dp;
    for(ll i=2; i<=n; i++) {
        if(prime[i]) dp.pb(i);
    }
    
    ll i = 0; vector<ll> B; B.pb(2);
    for(i=1; i<dp.size(); i++)
    {
        ll val = (2 * dp[i]);
        if(val <= n) {
            B.pb(dp[i]);
            continue;
        }
        else break;
    }
    
    ll rem = dp.size() - i;
    
    vector<ll> v1,v2;
    set<ll> s;
    
    for(ll j=i; j<dp.size(); j++) {
        v2.pb(dp[j]); s.insert(dp[j]);
    }
    
    for(ll i=2; i<=n; i++) {
        if(s.find(i) == s.end()) {
            v1.pb(i);
        }
    }
    
    if(k >= v1.size())
    {
        cout<<"YES"<<endl;
        
        show(v1); k -= v1.size();
        
        while(k > 0) {
            cout<<v2.back()<<" ";
            v2.pop_back();
            k--;
        }
        cout<<endl;
        
        return;
    }
    
    if(k <= v2.size()+1)
    {
        cout<<"YES"<<endl;
        
        cout<<1<<" "; k--;
        
        while(k > 0) {
            cout<<v2.back()<<" ";
            v2.pop_back();
            k--;
        }
        cout<<endl;
        
        return;
    }
    
    cout<<"NO"<<endl;
    
    return ;
}