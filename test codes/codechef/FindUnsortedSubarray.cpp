class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        if ( is_sorted(nums.begin() , nums.end()) ) return 0 ;
        int end = -1 ; 
        int mx_element_tillnow = nums[0];
        
        for( int i = 1 ; i < nums.size() ; i ++){
            if ( mx_element_tillnow > nums[i])
                end = i ;
            else 
                mx_element_tillnow = nums[i];
        }
        int start = 0 ;
        int mn_element_tillnow = nums[nums.size() - 1];
        
        for( int i = nums.size()-2 ; i >= 0 ; i --){
            if ( mn_element_tillnow < nums.at(i))
                start = i;
            else 
                mn_element_tillnow = nums.at(i);
        }
                return end - start + 1;
    }
};
