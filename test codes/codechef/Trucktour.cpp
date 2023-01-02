#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#define ll long long
#define pr pair<ll,ll>
#define mp make_pair
#define pb push_back
using namespace std;

int main() {
   queue<pr> Q;
   vector<pr> V;
   int ig;
   ll n,i,x,y,cnt=0,p=0,d=0,ans=0;
   cin>>n;
   for(i=1;i<=n;++i)
   {
      ig=scanf("%lld %lld",&x,&y);
      V.pb(mp(x,y));
   }
   while(Q.size()!=n)
   {
      if(p+V[cnt].first<V[cnt].second){

         while(!Q.empty()){
            V.pb(Q.front());
            Q.pop();
         }
         V.pb(V[cnt++]);
         ans=cnt;
         p=0;        
      }
      else{
         Q.push(V[cnt]);
         p+=V[cnt].first-V[cnt].second;
         ++cnt;
      }     
   }
   cout<<ans<<endl;
   return 0;
}
