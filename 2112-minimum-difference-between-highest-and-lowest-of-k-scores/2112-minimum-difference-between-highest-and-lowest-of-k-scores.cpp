class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        if (k == 1) return 0;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i+k -1 < nums.size() ; i++){
            int x =nums[i+k-1] - nums[i];
            ans = min(ans  , x);
        }
        return ans;
    }
};