class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> A(nums.begin(), nums.end());
        sort(A.begin(), A.end());
        int a = 1, b = 0, n = A.size();
        for(int i = 0; i < n; i++)
            if(A[i] != nums[i]){
                a = i;
                break;
            }
        for(int i = n - 1; i >= 0; i--)
            if(A[i] != nums[i]){
                b = i;
                break;
            }
        return b - a + 1;
    }
};
