class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int left = 0,ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;
            while (freq[nums[r]] > k){
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, r - left + 1);
        }
        return ans;
    }
};