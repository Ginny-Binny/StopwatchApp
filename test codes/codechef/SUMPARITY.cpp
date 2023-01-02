#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void sumparity() {
    ll n,a;cin>>n>>a;
    if(a%2==0) {
        if(n==1) cout<<"Even\n";
        else cout<<"Impossible\n";
        return;
    }
    if(n%2==0) cout<<"Even\n";
    else cout<<"Odd\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
      
        sumparity();
    }
}