#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0; // pointer to the current element in arr
        int j = 1; // pointer to the current positive integer
        while (k > 0) {
            if (i < arr.size() && arr[i] == j) {
                // current positive integer is in the array, skip it
                i++;
            } else {
                // current positive integer is missing, count it
                k--;
            }
            j++; // move to the next positive integer
        }
        return j - 1; // j is the kth missing positive integer
    }
};
