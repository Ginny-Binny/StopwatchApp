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


signed main(){



    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {


        ll m, x;
        cin >> m >> x;

        vll ans(x+1, 0);
        ans[1] = 1;
        --m;
        for(int i = 2; i <= x; i++){
            ll val = m%i;
            ++val;
            if(i==2){
                if(val == 1){
                    ans[i] = 2;
                }else{
                    ans[i] = 1;
                }
            }else{
                ll prev = ans[i-1];
                if(val == 1){
                    ans[i] = ans[i-1]+1;
                }else{
                    if(prev < val){
                        ans[i] = prev;
                    }else{
                        ans[i] = prev+1;
                    }
                }
            }
        }

        for(int i = 1; i <= x; i++){
            cout << ans[i] << " ";
        }cout << endl;





    }

    return 0;
}