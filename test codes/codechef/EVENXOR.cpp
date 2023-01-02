#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define uni(x)           x.erase(unique(x.begin(),x.end()),x.end());
#define ld               long double
#define ll               long long
#define endl             "\n"
#define dbg(x)           cout<<#x<<" is -> "<<x<<endl
#define speed_           ios_base::sync_with_stdio(false),cin.tie(0), cout.tie(0)
#define pb               push_back
#define pf               push_front
#define po               pop_back
#define mp               make_pair
#define sab(x)           x.begin(),x.end()
#define ff               first
#define ss               second
#define sz(x)            (int)x.size()
 
const int N=1e6;
const int M = 1000000007;
const int MM = 998244353;
const int inf=1e18;
const long double Pi= acos(-1);
 
vector<int>ans;
void s(){
 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
 
}
 
signed main(){
 
    speed_; 
 
    int t;
    t=1;
    cin>>t;
 
  
 
    for(int i=1;i<100000;i++){
        int curr=i;
        int coun=0;
        while(curr){
            coun++;
            curr=(curr&(curr-1));
        }
        if(coun%2==0){
            ans.pb(i);
        }
    }
 
    while(t--){
        s();
    }
 
return 0;
}