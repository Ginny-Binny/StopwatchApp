class Solution {
    List<int[]> tree[];
    boolean vis[];
    Integer ans;
    public int minScore(int n, int[][] roads) {
        tree = new ArrayList[n+1];
        vis = new boolean[n+1];
        ans = Integer.MAX_VALUE;
        for(int i=0;i<=n;i++) tree[i] = new ArrayList<>();
        for(int road[]: roads) {
            tree[road[0]].add(new int[]{road[1], road[2]});
            tree[road[1]].add(new int[]{road[0], road[2]});
        }
        dfs(1, 0);
        return ans;
    }
    public void dfs(int cur, int par) {
        if(vis[cur]) return;
        vis[cur] = true;
        for(int child[]: tree[cur]) {
            if(child[0] == par) continue;
            ans = Math.min(ans, child[1]);
            dfs(child[0], cur);
        }
    }
}