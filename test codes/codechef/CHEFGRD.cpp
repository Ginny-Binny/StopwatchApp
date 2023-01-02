#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define vi          vector<int>
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define endl        '\n'




signed main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {

        ll n, x, y;
        cin >> n >> x >> y;

        ll a = (abs(x - ((n+1)/2)))%2, b = (abs(y - ((n+1)/2)))%2;

        if((a && !b) || (!a && b)){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }






    }

    return 0;
}