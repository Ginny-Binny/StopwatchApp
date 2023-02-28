#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> heap;
    for (int stone : stones) {
        heap.push(stone);
    }
    while (heap.size() > 1) {
        int y = heap.top(); heap.pop();
        int x = heap.top(); heap.pop();
        if (x != y) {
            heap.push(y - x);
        }
    }
    if (heap.empty()) {
        return 0;
    } else {
        return heap.top();
    }
}
};