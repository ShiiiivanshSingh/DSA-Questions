class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int unc = 1; int achaa = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) unc++;
            else {
                 achaa = unc; 
                 unc = 1; 
                 }
            if(unc >= 2*k || min(achaa, unc) >= k) return true;
        }
        return false;
    }
};
