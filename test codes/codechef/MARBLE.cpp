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


bool isvowel(char c){
    if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'){
        return true;
    }
    return false;
}

signed main(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {

        int num;  cin>>num;
        string s1,s2;  cin>>s1>>s2;
        int res = INT_MAX;
        for(int i=0;i<26;i++){
            int temp_cost = 0;
            char ch = i+'a';
            for(int j=0;j<num;j++){
                char c1 = (s1[j]=='?')?ch:s1[j];
                char c2 = (s2[j]=='?')?ch:s2[j];
                if(c1!=c2){
                    if(isvowel(c1)&&isvowel(c2)){
                        temp_cost+=2;
                    }else if(isvowel(c1)==false&&isvowel(c2)==false){
                        temp_cost+=2;
                    }else{
                        temp_cost++;
                    }
                }
            }
            // cout<<ch<<nl;
            res = min(res,temp_cost);
        }cout<<res<<endl;


        
    }

    return 0;
}