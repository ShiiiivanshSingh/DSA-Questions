class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) up++;
            else up = 1;

            if (nums[i - 1] > nums[i]) down++;
            else down = 1;

            best = max({best, up, down});
        }
        return best;
    }
};