class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<int> meow;
        int seedhe = *max_element(nums.begin(), nums.end());
        int maut = *min_element(nums.begin(), nums.end());

        return 1LL*k*(seedhe-maut);
    }
};