class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> occ;
        int left = 0,ans = 0;
        for (int r = 0; r < nums.size() ; r++) {

            occ[nums[r]]++;
            while (occ[nums[r]] > k){
                occ[nums[left]]--;
                left++;
            }
            ans = max(ans, r-left + 1);
        }
        return ans;
    }
};