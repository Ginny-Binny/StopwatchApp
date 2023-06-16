#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i, n) for (int i = 0; i < n; i++)
#define VI vector<int>
#define VL vector<ll>
//int dp[2005][2005], n;
const int MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a = "mom", b = "dad";
        int j = 0, cnt = 0, ind, ind1;
        bool dad = false, mom = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == a[j])
            {
                cnt++;
                j++;
            }
            if (cnt == 3)
            {
                mom = true;
                ind = i;
            }
        }
        j = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == b[j])
            {
                cnt++;
                j++;
            }
            if (cnt == 3)
            {
                dad = true;
                ind1 = i;
            }
        }
        if (!dad && !mom)
            cout << "Goo-Goo\n";
        else if (dad && mom)
            cout << (ind < ind1) ? "Mom\n" : "Dad\n";
        else if (dad)
            cout << "Dad\n";
        else
            cout << "Mom\n";
    }
}