#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const vector<int>& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            vector<int> node = pq.top(); pq.pop();
            int cost = node[0], city = node[1], stops = node[2];
            if (city == dst) {
                return cost;
            }
            if (stops > k) {
                continue;
            }
            for (const pair<int, int>& neighbor : adjList[city]) {
                pq.push({cost + neighbor.second, neighbor.first, stops + 1});
            }
        }
        return -1;
    }
};