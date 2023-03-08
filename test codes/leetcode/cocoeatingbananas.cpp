class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool canFinish(vector<int>& piles, int h, int k) {
        int time = 0;
        for (int p : piles) {
            time += (p - 1) / k + 1; // ceil(p/k)
            if (time > h) return false;
        }
        return true;
    }
};
