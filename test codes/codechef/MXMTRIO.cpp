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
    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {

        ll n;
        cin >> n;

        vll arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll ans = 0;

        for(int i = 0; i < n; i++){
            if(i == n-1){
                ll val = arr[i] * (arr[n-2] - arr[0]);
                ans = max(ans, val);
            }else if(i == 0){
                ll val = arr[i] * (arr[n-1] - arr[1]);
                ans = max(ans, val);
            }else{
                ll val = arr[i] * (arr[n-1] - arr[0]);
                ans = max(ans, val);
            }
        }


        cout << ans << endl;




    }

    return 0;
}