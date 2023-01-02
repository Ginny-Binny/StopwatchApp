#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define ff          first
#define ss          second
#define pb          push_back
#define endl        '\n'


signed main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



   int tc;
   cin >> tc;

   while(tc--){

       ll n;
       cin >> n;

       string s;
       cin >> s;

       bool flag = true;

       ll cnt0 = 0, cnt1 = 0;
       for(auto x: s){
           if(x == '0'){
               cnt0++;
           }else{
               cnt1++;
           }
       }

       if (min(cnt0, cnt1) == 0) {
           flag = false;
       }
       
       if (min(cnt0, cnt1) >= 2) {
           ll move = cnt0 + cnt1 - (2LL * min(cnt0, cnt1));
           if (move % 2 == 0) {
               flag = false;
           }
       }

       if(flag){
           cout << "Alice" << endl;
       }else{
           cout << "Bob" << endl;
       }




   }

    return 0;
}