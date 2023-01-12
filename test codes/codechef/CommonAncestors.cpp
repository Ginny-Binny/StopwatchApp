#include <bits/stdc++.h>

using namespace std;

const int MX = 1e6 + 10;

int seg[4 * MX], lazy[4 * MX], beg[MX], fin[MX], dep[MX], cnt;
vector<int> adj[2][MX];

void updateNode(int idx, int v) {
seg[idx] += v;
lazy[idx] += v;

return;
}

void shift(int idx, int st, int ed) {
int lft = 2 * idx, rgt = lft + 1;

if (lazy[idx]) {
updateNode(lft, lazy[idx]);
updateNode(rgt, lazy[idx]);

lazy[idx] = 0;
}

return;
}

void update(int s, int e, int v, int idx = 1, int st = 0, int ed = cnt - 1) {
if (s > e || e < st || s > ed) return;

if (s == st && e == ed) {
updateNode(idx, v);

return;
}

int lft = 2 * idx, rgt = lft + 1, mid = (st + ed) / 2;

shift(idx, st, ed);

update(s, min(e, mid), v, lft, st, mid), update(max(s, mid + 1), e, v, rgt, mid + 1, ed);

seg[idx] = max(seg[lft], seg[rgt]);

return;
}

void dfs0(int u, int d) {
beg[u] = cnt++;
dep[u] = d;

for (auto v : adj[0][u]) dfs0(v, d + 1);

fin[u] = cnt - 1;

return;
}

void dfs1(int u, int d, int &ans) {
if (dep[u] == d) update(beg[u], fin[u], 1);

ans = max(ans, seg[1]);

for (auto v : adj[1][u]) {
dfs1(v, d + 1, ans);
}

if (dep[u] == d) update(beg[u], fin[u], -1);

return;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

int t;
cin >> t;

while (t--) {
cnt = 0;

int n;
cin >> n;

for (int i = 0; i <= 4 * n; i++) {
seg[i] = lazy[i] = 0;

if (i <= n) {
adj[0][i].clear();
adj[1][i].clear();
}
}

for (int j = 0; j < 2; j++) {
for (int i = 1; i <= n; i++) {
int p;
cin >> p;

adj[j][p != -1 ? p : 0].push_back(i);
}  }

dfs0(0, 0);
int ans = 0;
dfs1(0, 0, ans);
cout << ans - 1 << endl;
}

return 0;
}

