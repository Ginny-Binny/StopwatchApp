// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n, e; cin >> n >> e;
//     unordered_map<int, vector<int>> mp;
//     size_t maxSize = 0;
//     for (int i = 0; i < e; i++) {
//         int n1, n2; cin >> n1 >> n2;
//         mp[n1].push_back(n2);
//         mp[n2].push_back(n1);
//         maxSize = max(maxSize, max(mp[n1].size(), mp[n2].size()));
//     }
//     vector<int> results;
//     for (auto p : mp) {
//         int k = p.first;
//         if (p.second.size() == maxSize) {
//             results.push_back(k);
//         }
//     }
//     sort(begin(results), end(results));
//     for (int val : results) {
//         cout << val << " ";
//     }
//     cout<<"\n";
// }

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    int maxSize = 0;
    vector<int> nodes(n+1, 0);
    for (int i = 0; i < e; i++) {
        int n1, n2; cin >> n1 >> n2;
        nodes[n1]++;
        nodes[n2]++;
        maxSize = max(maxSize, max(nodes[n1], nodes[n2]));
    }
    vector<int> results;
    for (int i = 1; i <= n; i++) {
        if (nodes[i] == maxSize) results.push_back(i);
    }
    sort(begin(results), end(results));
    for (int val : results) {
        cout << val << " ";
    }
    cout << "\n";
}


