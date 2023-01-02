#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define vi          vector<int>
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define ld          long double
#define ff          first
#define ss          second
#define vs          vector<string>
#define vpll        vector<pll>
#define vb          vector<bool>
#define mp          make_pair
#define pb          push_back
#define endl        '\n'

const ll INF       = 2e18;
const ll mod       = 1000000007;
const ll mod2      = 998244353;




signed main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int tc = 0, tp = 1;
    cin >> tp;
    while (tc++ < tp)
    {

        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        ll l = 0, r = k - 1;
        ll idx = 1;

        string ans;

        while(l <= r){
            if(idx%2){
                ans.pb(s[l++]);
            }else{
                ans.pb(s[r--]);
            }
            idx ^= 1;
        }
        
        reverse(ans.begin(), ans.end());

        for(int i = k; i < n; i++){
            ans.pb(s[i]);
        }

        cout << ans << endl;



    }

    return 0;
}