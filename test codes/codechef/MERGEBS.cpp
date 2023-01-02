#include <bits/stdc++.h>
using namespace std;
#define maxN 200006
#define ll long long int
#define ld long double
#define MOD (ll)1e9 + 7
#define mod (ll)998244353
ll dp[1003][1003];
ll Recursion(ll i, ll j, string a, string b, ll tt)
{
    int n = a.length();
    if (i == n && j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans1 = INT_MAX, ans2 = INT_MAX;
    if (i < n)
    {
        if (a[i] == '1')
        {
            ans1 = (tt) + Recursion(i + 1, j, a, b, tt);
        }
        else
        {
            ans1 = Recursion(i + 1, j, a, b, tt - 1);
        }
    }
    if (j < n)
    {
        if (b[j] == '1')
        {
            ans2 = (tt) + Recursion(i, j + 1, a, b, tt);
        }
        else
        {
            ans2 = Recursion(i, j + 1, a, b, tt - 1);
        }
    }
    return dp[i][j] = min(ans1, ans2);
}
void Solve()
{
    ll n;
    cin>>n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 1003; i++)
    {
        for (int j = 0; j < 1003; j++)
            dp[i][j] = -1;
    }
    ll cnt = 0;
    for (auto it : a)
    {
        cnt += (it == '0');
    }
    for (auto it : b)
    {
        cnt += (it == '0');
    }

    cout << Recursion(0, 0, a, b, cnt) << endl;
}
int main()
{
   
    ll p;
    cin >> p;
    while (p--)
        Solve();
}