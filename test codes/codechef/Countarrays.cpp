#include"bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long ll;

#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb push_back

const ll mod = 1000000007;

ll modexp(ll a, ll b) {ll ans = 1; while (b > 0) {if ((b & 1) == 1) {ans = (ans * a) % mod;} b >>= 1; a = (a * a) % mod;} return ans;}
ll gcd(ll a, ll b) {if (b == 0) return a; return gcd(b, a % b);}

void fast() {ios::sync_with_stdio(false); cin.tie(NULL);}


void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    vector<int> g(n+1);
    for(int i = 1; i <= n; i++){
        cin >> g[i];
    }
    // debug(g);
    vector<int> vis(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[1][0] = 0;
    dp[1][1] = m;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i-1][0] * (m - 2) % mod + dp[i-1][1] * (m - 1) % mod) % mod;
        dp[i][1] = dp[i-1][0];
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            int cur = i;
            int count = 0;
            while(!vis[cur]){
                count++;
                vis[cur] = 1;
                cur = g[cur];
            }
            if(vis[cur] == 2){
                ans = ans * modexp(m - 1, count) % mod;
            }
            else{
                int cycle_len = 1;
                for(int j = g[cur]; j != cur; j = g[j]){
                    cycle_len++;
                }
                ans = ans * modexp(m - 1, count - cycle_len) % mod;
                ans = ans * dp[cycle_len][0] % mod;
            }
            cur = i;
            while(vis[cur] != 2){
                vis[cur] = 2;
                cur = g[cur];
            }
        }
    }
    cout << ans << '\n';
};

int main() {

	fast();
	ll tt = 1;
	cin >> tt;
	for (ll i = 1; i <= tt; i++) {
		solve();
	}
}
