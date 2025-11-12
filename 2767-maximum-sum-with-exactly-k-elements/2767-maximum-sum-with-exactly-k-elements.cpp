class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.rbegin() , nums.rend());

        int n = nums.size();

        int ans  = 0 ; 

        for(int i = 0 ; i< k ; i++){
            ans  += nums[0];
            nums[0] = nums[0] + 1;
        }
     return ans;
    }
};