#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0; // edge case
        unordered_map<int, vector<int>> indices; // map each value to its indices
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false); // mark visited indices
        visited[0] = true;
        queue<int> q({0}); // BFS queue
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front(); q.pop();
                if (curr == n - 1) return steps; // reached the last index
                // add neighbors that haven't been visited
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                // add neighbors with the same value that haven't been visited
                for (int next : indices[arr[curr]]) {
                    if (next != curr && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
                // clear the indices of the current value to save memory
                indices[arr[curr]].clear();
            }
            steps++;
        }
        return -1; // should never happen
    }
};
