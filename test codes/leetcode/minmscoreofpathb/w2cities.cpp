class Solution {
public:
    int minimumScorePath(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            graph[i][i] = 0;
        }
        for (const auto& road : roads) {
            int u = road[0] - 1;
            int v = road[1] - 1;
            int w = road[2];
            graph[u][v] = min(graph[u][v], w);
            graph[v][u] = min(graph[v][u], w);
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }
        
        return graph[0][n-1];
    }
};
