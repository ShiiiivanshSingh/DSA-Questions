class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), a = min_element(nums.begin(), nums.end()) - nums.begin(), b = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(a, b), r = max(a, b);
        return min( {r + 1,n - l, l + 1 + n - r});
    }
};