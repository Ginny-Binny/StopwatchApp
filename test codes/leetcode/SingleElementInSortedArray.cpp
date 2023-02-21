#include <iostream>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            if (mid % 2 == 0) {  // mid is even
                if (nums[mid] == nums[mid+1]) {
                    left = mid + 2;
                } else {
                    right = mid - 2;
                }
            } else {  // mid is odd
                if (nums[mid] == nums[mid-1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return nums[left];
    }
};
