#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector <long> value;
long x;
long max(long a,long b)
{
if(a>=b)
{
return a;
}
else
{
return b;
}
}
long dfs(vector <long>v[],long a,long b)
{
long i;
long cal=value[a-1];
for(i=0; i<v[a].size(); i++)
{
if(v[a][i]!=b)
{
cal+=dfs(v,v[a][i],a);
}
}
return max(cal,-x);
}
int main() {
long t;
cin>>t;
while(t--)
{
value.clear();
long n;
cin>>n>>x;
vector <long> v[n+1];
long i;
long a,b;
for(i=1; i<=n; i++)
{
cin>>a;
value.push_back(a);
}
for(i=0; i<n-1; i++)
{
cin>>a>>b;
v[a].push_back(b);
v[b].push_back(a);
}
long cal=dfs(v,1,-1);
printf("%ld\n",cal);
}
}
