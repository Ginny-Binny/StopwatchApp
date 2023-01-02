#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> z_function(string s)
{

    int n =(int) s.length();
    vector<int> z(n);
    for(int i=1,l=0 , r=0;i<n; ++i)
    {
        if(i<=r){
            z[i] = min (r - i + 1, z[i - 1]);
        }

        while ( i+z[i]<n && s[z[i]] == s[i+z[i]]) {
            ++z[i];
        }
        if(i+z[i] - 1 > r){
            l = i, r=i+z[i]-1; // l or 1? 
        }
    }
    return z;
}

vector<vector<ll>> stB;
ll query(ll x , ll y)
{
    if(x>y) return 0;
    ll f = log2(y-x+1);
    return max(stB[x][f], stB[y-(1<<f) + 1][f]);
}
int main()
{
  ll T;
  cin>> T;
  while(T--)
  {
      string S1 , S2, x;
      cin>>S1>>S2>>x;
      ll n =x.length();
      ll a = S1.length(), b=S2.length();
      vector<int> va = z_function(S1 + '#' + x);
      vector<int> vb = z_function(S1 + '#' + x); 
      vector<ll> A(n,0), B(n,0);
      for(ll i=0; i<n; i++)
      A[i]= va[i+ a+1], B[i]= vb[i+b+1];

      stB.assign(n, vector<ll>(30,0));
      for(ll i=0; i<n;i++)
      {
          A[i] += i-1, B[i] += i -1;
          stB[i][0] = B[i];
      }

      for(ll j=1; j<30; j++)
      for(ll i=0 ; i<n; i++)
      if(i+(1 << j - 1)<n)
      stB[i][j]= max(stB[i][j -1 ], stB[i + (1<< j - 1 )][j - 1]);
      else break;

      ll ans =0;
      for(ll i=0; i<n; i++)
      {
          ll cur =max(A[i], B[i]) - i +2;
          cur=max(cur, query(i,min(n-1, A[i] +1))-i-1);
          ans+=cur;
      }
      cout<< ans <<endl;
  }
}