#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> solution(vector<int> a) {
    int n = a.size();
    unordered_map<int, int> count; // Count the number of occurrences of each integer in a
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    for (auto it = count.begin(); it != count.end(); it++) {
        if (it->second > 2) { // If any integer occurs more than twice, there is no solution
            return {};
        }
    }
    vector<int> result1, result2;
    for (auto it = count.begin(); it != count.end(); it++) {
        int num = it->first;
        int freq = it->second;
        if (freq == 2) { // If the integer occurs twice, put it in both result arrays
            result1.push_back(num);
            result2.push_back(num);
        } else { // Otherwise, put it in one of the result arrays, following the condition that they should have equal sizes
            if (result1.size() > result2.size()) {
                result2.push_back(num);
            } else {
                result1.push_back(num);
            }
        }
    }
    return {result1, result2};
}

int main() {
    vector<int> a = {2, 1, 2, 3, 3, 4};
    vector<vector<int>> result = solution(a);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
