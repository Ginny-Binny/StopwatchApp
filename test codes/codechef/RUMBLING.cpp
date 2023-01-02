#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define int ll

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int Num; cin >> Num;
        string S; cin >> S;
        int a, b; cin >> a >> b;

        vi minE(Num), minW(Num);
        for(int x = 0; x < Num; x++){
            if(S[x] == 'E') minE[x] = 0, minW[x] = 2*min(a,b);
            if(S[x] == 'W') minE[x] = 2*min(a,b), minW[x] = 0;
            if(S[x] == 'N') minE[x] = min(a,3*b), minW[x] = min(3*a, b);
            if(S[x] == 'S') minE[x] = min(3*a,b), minW[x] = min(a, 3*b);
        }

        for(int x = 1; x < Num; x++) minE[x] += minE[x-1];
        for(int x = Num-2; x >= 0; x--) minW[x] += minW[x+1];

        int ans = min(minE[Num-1], minW[0]);
        for(int x = 0; x < Num-1; x++)
            ans = min(ans, minE[x]+minW[x+1]);
        cout << ans << "\n";
    }
    
    return 0;
}