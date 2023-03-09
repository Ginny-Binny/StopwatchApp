#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string longestDupSubstring(string s) {
    int n = s.size();
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = s[i] - 'a';
    }
    int left = 1, right = n - 1, mid;
    while (left <= right) { // binary search for the length of the longest duplicate substring
        mid = left + (right - left) / 2;
        bool found = false;
        unordered_map<int, vector<int>> hash; // hash values -> indices
        int p = 1, val = 0;
        for (int i = 0; i < mid; i++) { // calculate the hash value of the first substring of length mid
            val = (val * 26 + nums[i]) % 19260817;
            p = (p * 26) % 19260817;
        }
        hash[val].push_back(0);
        for (int i = mid; i < n; i++) { // calculate the hash values of the remaining substrings of length mid and check for duplicates
            val = ((val * 26) % 19260817 + nums[i] - (nums[i - mid] * p) % 19260817 + 19260817) % 19260817; // update the hash value using the rolling hash technique
            if (hash.count(val)) {
                for (int j = 0; j < hash[val].size(); j++) {
                    if (s.substr(hash[val][j], mid) == s.substr(i - mid + 1, mid)) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
            hash[val].push_back(i - mid + 1);
        }
        if (found) left = mid + 1;
        else right = mid - 1;
    }
    int len = right;
    unordered_map<int, vector<int>> hash;
    int p = 1, val = 0;
    for (int i = 0; i < len; i++) {
        val = (val * 26 + nums[i]) % 19260817;
        p = (p * 26) % 19260817;
    }
    hash[val].push_back(0);
    for (int i = len; i < n; i++) {
        val = ((val * 26) % 19260817 + nums[i] - (nums[i - len] * p) % 19260817 + 19260817) % 19260817;
        if (hash.count(val)) {
            for (int j = 0; j < hash[val].size(); j++) {
                if (s.substr(hash[val][j], len) == s.substr(i - len + 1, len)) {
                    return s.substr(hash[val][j], len);
                }
            }
        }
        hash[val].push_back(i - len + 1);
    }
    return "";
}
