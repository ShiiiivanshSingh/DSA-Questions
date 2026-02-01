class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        if(nums.size()<2) return nums[0]+nums[1] ; 
        sort(nums.begin()+1, nums.end());
        return ans +nums[1] + nums[2];
    }
};