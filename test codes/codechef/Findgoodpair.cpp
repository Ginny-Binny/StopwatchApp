int findGoodPairs(int n, int k, vector<int> &arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        int correctPairs = 0;
        for (auto p: mp) {
            vector<int> indices = p.second;
            for (int i = 0; i < indices.size(); i++) {
                int val = indices[i] + k;
                int bound = lower_bound(indices.begin(), indices.end(), val) - indices.begin();
                correctPairs += (indices.size() - bound);
            }
        }
        return correctPairs;
    }