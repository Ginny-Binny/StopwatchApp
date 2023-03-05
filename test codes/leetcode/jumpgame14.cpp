#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minSteps(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) {
        return 0;
    }
    queue<int> q;
    unordered_map<int, int> dist;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int d = dist[i];
        if (i == n - 1) {
            return d;
        }
        if (i + 1 < n && dist.find(i + 1) == dist.end()) {
            q.push(i + 1);
            dist[i + 1] = d + 1;
        }
        if (i - 1 >= 0 && dist.find(i - 1) == dist.end()) {
            q.push(i - 1);
            dist[i - 1] = d + 1;
        }
        for (int j = 0; j < n; j++) {
            if (arr[j] == arr[i] && j != i && dist.find(j) == dist.end()) {
                q.push(j);
                dist[j] = d + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 2, 3, 1, 5, 1};
    int steps = minSteps(arr);
    cout << steps << endl; // Output: 3
    return 0;
}
