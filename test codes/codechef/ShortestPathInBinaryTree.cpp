#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
ll t;
cin>>t;

while(t--)
{
ll a,b;
cin>>a>>b;

vector<ll>acnt;
vector<ll>bcnt;
while(a!=1)
{
acnt.push_back(a);
a=a/2;
}
acnt.push_back(1);
while(b!=1)
{
bcnt.push_back(b);
b=b/2;
}
bcnt.push_back(1);
sort(acnt.begin(),acnt.end());
sort(bcnt.begin(),bcnt.end());
ll root;
ll pos;
for(ll i=0;i<min(acnt.size(),bcnt.size());i++)
{
if(acnt[i]==bcnt[i])
{
root=acnt[i];
pos=i;
}
}
ll ans=(acnt.size()-1)-pos+(bcnt.size()-1)-pos;
cout<<ans<<"\n";
}
}

